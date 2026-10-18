from __future__ import annotations

import argparse
import json
from pathlib import Path

from .compare import compare_summaries
from .runner import run_suite


def main() -> None:
    parser = argparse.ArgumentParser(
        prog="simreg",
        description="Run RTL simulations and analyze runtime regressions."
    )
    sub = parser.add_subparsers(dest="command", required=True)

    run_parser = sub.add_parser("run", help="Build and run a simulation suite")
    run_parser.add_argument("--config", type=Path, required=True)
    run_parser.add_argument("--out", type=Path, required=True)
    run_parser.add_argument("--jobs", type=int, default=1)
    run_parser.add_argument("--timeout", type=int, default=60)

    cmp_parser = sub.add_parser("compare", help="Compare two summary.json files")
    cmp_parser.add_argument("--baseline", type=Path, required=True)
    cmp_parser.add_argument("--current", type=Path, required=True)
    cmp_parser.add_argument("--threshold-percent", type=float, default=20.0)

    args = parser.parse_args()
    if args.command == "run":
        result = run_suite(args.config, args.out, args.jobs, args.timeout)
        print(json.dumps(result, indent=2))
        raise SystemExit(1 if result["tests_failed"] else 0)
    if args.command == "compare":
        result = compare_summaries(
            args.baseline, args.current, args.threshold_percent
        )
        print(json.dumps(result, indent=2))
        raise SystemExit(
            1 if result["regressions"] or result["functional_failures"] else 0
        )


if __name__ == "__main__":
    main()
