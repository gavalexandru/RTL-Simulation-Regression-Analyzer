# RTL Simulation Regression Analyzer

A small Python tool for running RTL simulations with Verilator and collecting test results in JSON format.

The project includes a SystemVerilog FIFO, a testbench, and a command-line interface for running simulation tests and analyzing regression results.

## Project Structure

```text
.
├── config/     # Test suite configuration
├── rtl/        # FIFO implementation
├── tb/         # SystemVerilog testbench
├── simreg/     # Simulation runner and result analysis
├── tests/      # Python unit tests
└── results/    # Simulation output and reports
```

## Requirements

- Python 3.10 or newer
- Verilator
- GNU Make
- A C++ compiler
- Linux or WSL

## Setup

Create and activate a virtual environment:

```bash
python3 -m venv .venv
source .venv/bin/activate
```

Install the project and development dependencies:

```bash
python -m pip install -e ".[dev]"
```

## Run the Simulation

Run the configured test suite:

```bash
simreg run --config config/suite.json --out results/first_run
```

The runner invokes Verilator, builds the testbench, executes the simulation, and saves the results under the specified output directory.

The generated `summary.json` contains the number of tests, pass/fail status, execution duration, return code, and log location. The total suite wall-clock time is also recorded.

## Compare Results

The project includes a command for comparing regression reports:

```bash
simreg compare --help
```

Use the options shown by the command to compare a new run against a baseline.

## Run Unit Tests

```bash
pytest -v
```

The Python tests cover configuration validation, runtime regression detection, and functional failure reporting.

## Current Scope

The project currently uses a FIFO simulation as its example workload. It combines a basic RTL testbench with Python-based simulation automation and JSON result reporting.
