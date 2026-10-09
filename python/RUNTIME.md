# Python Runtime Documentation

## Environment
- Version: [output of `python --version`]
- Run command: `python main.py`

## Type System
- **Dynamic:** types are attached to values and checked while the program runs. A variable can be reassigned from `int` to `str` (test 2).
- **Strong:** no silent conversion between unrelated types. `5 + "3"` raises a `TypeError` (tests 1 and 3).

## Execution Strategy
Source code is compiled to **bytecode** (`.pyc`) and executed by the **Python virtual machine** (CPython). There is no separate compile step for the user.

## Results
![Python results](../screenshots/python-results.png)

| Test | Result | Caught when? |
|---|---|---|
| 1. `5 + "3"` | `TypeError` | Runtime |
| 2. Reassign int to str | Allowed | n/a |
| 3. `add_one("a")` | `TypeError` | Runtime |
| 4. `5 + 2.5` | `7.5` | n/a (numeric promotion) |

## Observations
The program ran line by line, so the output from the earlier tests printed before the error appeared. `5 + "3"` raised a `TypeError` at runtime instead of producing a value, which shows that Python is strongly typed. Reassigning `v` from an integer to a string worked without complaint, which shows that it is dynamically typed. I had to wrap the risky lines in `try/except` to let the program continue past the errors.