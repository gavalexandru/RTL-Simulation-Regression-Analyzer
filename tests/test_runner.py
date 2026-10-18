import json
from pathlib import Path

import pytest

from simreg.runner import load_config


def test_loads_valid_config(tmp_path):
    config = tmp_path / "suite.json"
    config.write_text(json.dumps({
        "tests": [{"name": "smoke", "source": "tb.sv", "top": "tb"}]
    }), encoding="utf-8")
    assert load_config(config)["tests"][0]["name"] == "smoke"


def test_rejects_empty_suite(tmp_path):
    config = tmp_path / "suite.json"
    config.write_text('{"tests": []}', encoding="utf-8")
    with pytest.raises(ValueError):
        load_config(config)


def test_rejects_missing_fields(tmp_path):
    config = tmp_path / "suite.json"
    config.write_text('{"tests": [{"name": "smoke"}]}', encoding="utf-8")
    with pytest.raises(ValueError):
        load_config(config)
