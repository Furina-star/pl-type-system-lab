# C Runtime Documentation

## Environment
- Compiler: **gcc (Rev4, Built by MSYS2 project) 16.2.0**
- Platform: Windows, MSYS2 toolchain
- Compile from `c/`: `gcc main.c -o main`
- Run in PowerShell: `.\main.exe`
- Optional warnings: `gcc -Wall -Wextra -Wconversion main.c -o main`

## Type system
- **Static:** Variables have declared types known before execution. Assigning `'A'` to an `int` variable does not change that variable's type.
- **Conventionally weak:** C permits many implicit arithmetic conversions. A compiler may warn about lossy conversions when appropriate warning flags are enabled, so this is not the same as lacking compile-time type checking.

## Execution strategy
GCC compiles the source ahead of time into native machine code. The resulting executable runs without a language interpreter or virtual machine.

## Results
![C results](../screenshots/c-results.png)

| Test | Result | Explanation |
|---|---|---|
| `5 + '3'` | `56` | `'3'` is a character, **not** the string `"3"`. On this ASCII-based system it has the code 51, promoted for addition. |
| `v = 'A'` where `v` is `int` | `65` | `'A'` has code 65 on this system; `v` remains an integer variable. |
| `add_one(3.9)` | `4` | Conversion to the function's `int` parameter changes 3.9 to 3; the function adds 1. |
| `int r = 5 + 2.5` | `7` | The addition produces floating-point 7.5; the assignment to `int` truncates the fraction. |

## Observations
C's compiler permits the implicit conversions demonstrated here. The character test differs from the string test in Python and JavaScript. The mixed numeric expression is evaluated as floating-point before an assignment conversion discards its fractional part. The program can compile and run despite potentially lossy conversions; `-Wconversion` can reveal additional diagnostics.
