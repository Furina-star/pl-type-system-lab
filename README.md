# Type Systems Across Programming Languages

A Programming Languages laboratory exploring four type-system combinations through comparable experiments and documenting how each program executes.

## Languages and environments

| Language | Type checking | Strong/weak classification | Execution strategy | Version |
|---|---|---|---|---|
| C | Static | Conventionally weak | Ahead-of-time native compilation | GCC 16.2.0 (MSYS2 Rev4) |
| Rust | Static | Strong | Ahead-of-time native compilation | rustc 1.98.1 (48a229cea 2026-09-01) |
| Python | Dynamic | Strong | CPython bytecode VM | Python 3.14.7 |
| JavaScript | Dynamic | Conventionally weak | V8 bytecode interpreter and optimizing JIT | Node.js v24.19.0 |

**Terminology:** Static and dynamic typing describe whether relevant type checks occur before or during program execution. *Strong* and *weak* are informal classifications without one universally accepted definition. Here, they compare how strictly languages restrict mixed-type operations and how readily they perform implicit conversions. Weak typing does not mean the language never raises type errors, and strong typing does not mean conversions are never possible. Compilation strategy is separate from type-system classification.

## Experiments

1. **Numeric plus character/string:** C uses `5 + '3'` (a character, not a string); Python and JavaScript use `5 + "3"`. Rust demonstrates an explicit parse in `main.rs` and an invalid mixed-type expression in `error.rs`.
2. **Reassignment:** Python and JavaScript rebind a variable from a number to a string. C assigns a character value into an existing `int` variable without changing its declared type. Rust permits reassignment to a compatible type, but not an incompatible one.
3. **Function arguments:** C converts `3.9` to an integer parameter; Python's string argument produces a runtime error inside the function; JavaScript concatenates the string; Rust rejects the string argument at compile time.
4. **Integer and floating-point values:** In C, `5 + 2.5` evaluates to `7.5`, which is truncated to `7` when assigned to `int`. Rust's demonstrated mix requires an explicit cast. Python calculates `7.5`; JavaScript does as well, but both ordinary numeric literals have the `number` type.

These tests examine the same questions but are not identical expressions across languages; notably, C uses a **character** instead of a string and a floating-point function argument instead of a string argument.

## Folder structure

```text
c/            main.c, RUNTIME.md
rust/         main.rs, error.rs, RUNTIME.md
python/       main.py, RUNTIME.md
javascript/   main.js, RUNTIME.md
screenshots/   recorded program output and compiler errors
docs/          runtime-documentation.pdf
```

## Run the programs

Run the following from each language's folder on Windows PowerShell.

| Language | Command |
|---|---|
| C | `gcc main.c -o main` then `.\main.exe` |
| Rust | `rustc main.rs` then `.\main.exe`; run `rustc error.rs` separately for expected compiler diagnostics |
| Python | `python main.py` |
| JavaScript | `node main.js` |

For C conversion warnings, use `gcc -Wall -Wextra -Wconversion main.c -o main`. A permitted implicit conversion can still trigger a compiler warning.

## Key findings

- C and Rust perform static type checking, but C allows the implicit numeric conversions shown here while Rust rejects the incompatible expressions in `error.rs`.
- Python and JavaScript determine whether the operations are valid at runtime. Both allow rebinding a variable to a value of another type.
- Python raises `TypeError` for the string-plus-integer examples, whereas JavaScript coerces values in these specific operations. JavaScript **can** raise `TypeError` for other operations, such as mixing `BigInt` and `Number` in addition.
- Rust reports the demonstrated invalid expressions before execution, but it can still fail at runtime: `parse().unwrap()` panics if parsing fails.
- The Rust failing program illustrates compile-time errors, while the corrected Rust program demonstrates explicit conversions and compatible assignments.

## Detailed documentation

- [C runtime](c/RUNTIME.md)
- [Rust runtime](rust/RUNTIME.md)
- [Python runtime](python/RUNTIME.md)
- [JavaScript runtime](javascript/RUNTIME.md)
- [Consolidated runtime documentation (PDF)](docs/runtime-documentation.pdf)
- [Program output and error screenshots](screenshots/)

## Conclusion

The programs show different policies for type checking and implicit conversion. Rust rejects the deliberately incompatible expressions at compile time, Python reports errors as the invalid operations execute, and C and JavaScript perform conversions in the specific examples used. These outcomes should not be generalized into claims that any language catches every error or never raises a type error.
