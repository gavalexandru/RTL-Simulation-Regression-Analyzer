from __future__ import annotations

import json
import os
import shutil
import subprocess
import time
from concurrent.futures import ThreadPoolExecutor, as_completed
from pathlib import Path
from typing import Any


def load_config(config_path: Path) -> dict[str, Any]:
    with config_path.open(encoding="utf-8") as f:
        data = json.load(f)
    if not isinstance(data.get("tests"), list) or not data["tests"]:
        raise ValueError("Config must contain a non-empty 'tests' list")
    for item in data["tests"]:
        for field in ("name", "source", "top"):
            if not item.get(field):
                raise ValueError(f"Each test requires a non-empty '{field}'")
    return data


def _run_one(test: dict[str, Any], repo_root: Path, out_dir: Path,
             timeout_seconds: int) -> dict[str, Any]:
    name = test["name"]
    test_dir = out_dir / name
    test_dir.mkdir(parents=True, exist_ok=True)
    source = (repo_root / test["source"]).resolve()
    if not source.is_file():
        return {
            "name": name, "status": "FAIL", "duration_seconds": 0.0,
            "return_code": None, "log": str((test_dir / "simulation.log").relative_to(out_dir)),
            "error": f"Source file not found: {source}"
        }

    verilator = shutil.which("verilator")
    if not verilator:
        return {
            "name": name, "status": "FAIL", "duration_seconds": 0.0,
            "return_code": None, "log": str((test_dir / "simulation.log").relative_to(out_dir)),
            "error": "Verilator not found on PATH"
        }

    obj_dir = test_dir / "obj_dir"
    binary = obj_dir / f"V{test['top']}"
    cmd = [
        verilator, "--binary", "--timing", "-Wall", "-Wno-fatal",
        "--top-module", test["top"], "--Mdir", str(obj_dir),
    ]
    for define in test.get("defines", []):
        cmd.append(f"-D{define}")
    cmd.extend([str(repo_root / "rtl/fifo.sv"), str(source)])

    log_path = test_dir / "simulation.log"
    start = time.perf_counter()
    return_code: int | None = None
    error = None
    try:
        build = subprocess.run(
            cmd, cwd=repo_root, capture_output=True, text=True,
            timeout=timeout_seconds, check=False
        )
        with log_path.open("w", encoding="utf-8") as log:
            log.write("$ " + " ".join(cmd) + "\n")
            log.write(build.stdout)
            log.write(build.stderr)
        if build.returncode != 0:
            return_code = build.returncode
            error = "Verilator build failed; inspect simulation.log"
        else:
            run = subprocess.run(
                [str(binary)], cwd=repo_root, capture_output=True, text=True,
                timeout=timeout_seconds, check=False
            )
            with log_path.open("a", encoding="utf-8") as log:
                log.write("\n$ " + str(binary) + "\n")
                log.write(run.stdout)
                log.write(run.stderr)
            return_code = run.returncode
            if run.returncode != 0:
                error = "Simulation failed; inspect simulation.log"
    except subprocess.TimeoutExpired:
        error = f"Timed out after {timeout_seconds} seconds"
        return_code = -1
        with log_path.open("a", encoding="utf-8") as log:
            log.write("\nERROR: " + error + "\n")
    except OSError as exc:
        error = str(exc)
        with log_path.open("a", encoding="utf-8") as log:
            log.write("\nERROR: " + error + "\n")

    duration = time.perf_counter() - start
    return {
        "name": name,
        "status": "PASS" if return_code == 0 else "FAIL",
        "duration_seconds": round(duration, 6),
        "return_code": return_code,
        "log": str(log_path.relative_to(out_dir)),
        "error": error,
    }


def run_suite(config_path: Path, out_dir: Path, jobs: int = 1,
              timeout_seconds: int = 60) -> dict[str, Any]:
    if jobs < 1:
        raise ValueError("jobs must be >= 1")
    if timeout_seconds < 1:
        raise ValueError("timeout_seconds must be >= 1")

    suite_start = time.perf_counter()
    config_path = config_path.resolve()
    repo_root = config_path.parent.parent
    config = load_config(config_path)
    out_dir.mkdir(parents=True, exist_ok=True)

    results: list[dict[str, Any]] = []
    with ThreadPoolExecutor(max_workers=jobs) as pool:
        futures = {
            pool.submit(_run_one, test, repo_root, out_dir, timeout_seconds): test["name"]
            for test in config["tests"]
        }
        for future in as_completed(futures):
            results.append(future.result())

    results.sort(key=lambda item: item["name"])
    summary = {
        "schema_version": 1,
        "jobs": jobs,
        "tests_total": len(results),
        "tests_passed": sum(r["status"] == "PASS" for r in results),
        "tests_failed": sum(r["status"] == "FAIL" for r in results),
        "total_wall_seconds": round(time.perf_counter() - suite_start, 6),
        "tests": results,
    }
    (out_dir / "summary.json").write_text(
        json.dumps(summary, indent=2) + "\n", encoding="utf-8"
    )
    lines = [
        "# Simulation run summary", "",
        f"- Tests: {summary['tests_total']}",
        f"- Passed: {summary['tests_passed']}",
        f"- Failed: {summary['tests_failed']}",
        f"- Parallel jobs: {jobs}", "",
        "| Test | Status | Duration (s) | Log |",
        "|---|---:|---:|---|",
    ]
    for result in results:
        lines.append(
            f"| {result['name']} | {result['status']} | "
            f"{result['duration_seconds']:.6f} | `{result['log']}` |"
        )
    (out_dir / "report.md").write_text("\n".join(lines) + "\n", encoding="utf-8")
    return summary
