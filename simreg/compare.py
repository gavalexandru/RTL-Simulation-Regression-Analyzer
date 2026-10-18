from __future__ import annotations

import json
from pathlib import Path
from typing import Any


def compare_summaries(baseline_path: Path, current_path: Path,
                      threshold_percent: float = 20.0) -> dict[str, Any]:
    if threshold_percent < 0:
        raise ValueError("threshold_percent must be >= 0")
    baseline = json.loads(baseline_path.read_text(encoding="utf-8"))
    current = json.loads(current_path.read_text(encoding="utf-8"))
    base_tests = {t["name"]: t for t in baseline.get("tests", [])}
    curr_tests = {t["name"]: t for t in current.get("tests", [])}
    comparisons = []

    for name in sorted(set(base_tests) | set(curr_tests)):
        old = base_tests.get(name)
        new = curr_tests.get(name)
        if old is None or new is None:
            comparisons.append({
                "name": name, "status": "ADDED" if old is None else "REMOVED",
                "baseline_seconds": old["duration_seconds"] if old else None,
                "current_seconds": new["duration_seconds"] if new else None,
                "change_percent": None,
            })
            continue

        old_time = float(old["duration_seconds"])
        new_time = float(new["duration_seconds"])
        if old_time <= 0:
            change = None
            status = "NO_BASELINE"
        else:
            change = (new_time - old_time) / old_time * 100.0
            status = "REGRESSION" if change > threshold_percent else "OK"
        if old["status"] == "PASS" and new["status"] != "PASS":
            status = "FUNCTIONAL_FAILURE"
        comparisons.append({
            "name": name, "status": status,
            "baseline_seconds": old_time, "current_seconds": new_time,
            "change_percent": None if change is None else round(change, 2),
        })

    return {
        "threshold_percent": threshold_percent,
        "regressions": sum(x["status"] == "REGRESSION" for x in comparisons),
        "functional_failures": sum(x["status"] == "FUNCTIONAL_FAILURE" for x in comparisons),
        "comparisons": comparisons,
    }
