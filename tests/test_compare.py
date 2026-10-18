import json
from pathlib import Path

import pytest

from simreg.compare import compare_summaries


def write_summary(path: Path, duration: float, status: str = "PASS") -> None:
    path.write_text(json.dumps({
        "tests": [{
            "name": "fifo_basic",
            "status": status,
            "duration_seconds": duration
        }]
    }), encoding="utf-8")


def test_detects_runtime_regression(tmp_path):
    baseline = tmp_path / "base.json"
    current = tmp_path / "current.json"
    write_summary(baseline, 10.0)
    write_summary(current, 13.0)
    result = compare_summaries(baseline, current, threshold_percent=20)
    assert result["regressions"] == 1
    assert result["comparisons"][0]["change_percent"] == 30.0


def test_no_regression_under_threshold(tmp_path):
    baseline = tmp_path / "base.json"
    current = tmp_path / "current.json"
    write_summary(baseline, 10.0)
    write_summary(current, 11.0)
    result = compare_summaries(baseline, current, threshold_percent=20)
    assert result["regressions"] == 0
    assert result["comparisons"][0]["status"] == "OK"


def test_functional_failure_is_detected(tmp_path):
    baseline = tmp_path / "base.json"
    current = tmp_path / "current.json"
    write_summary(baseline, 10.0, "PASS")
    write_summary(current, 10.2, "FAIL")
    result = compare_summaries(baseline, current)
    assert result["functional_failures"] == 1


def test_rejects_negative_threshold(tmp_path):
    baseline = tmp_path / "base.json"
    current = tmp_path / "current.json"
    write_summary(baseline, 1.0)
    write_summary(current, 1.0)
    with pytest.raises(ValueError):
        compare_summaries(baseline, current, -1)
