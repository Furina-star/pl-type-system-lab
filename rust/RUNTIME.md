# Rust Runtime Documentation

## Environment
- Compiler: **rustc 1.98.1 (48a229cea 2026-09-01)**
- Compile working version from `rust/`: `rustc main.rs`
- Run in PowerShell: `.\main.exe`
- Compile error demonstration: `rustc error.rs` (expected failure)

## Type system
- **Static:** Rust checks types before execution. `mut` permits reassignment to a compatible value; it does not let the variable change type.
- **Strong:** Rust does not implicitly convert an `&str` to an integer or mix incompatible integer/float operand types. The working example uses explicit string parsing and numeric casting.

## Execution strategy
Rust compiles ahead of time to native machine code. A compilation failure prevents a new executable from being generated from the failing source file; a previously compiled executable may still exist.

## Results

### `error.rs` (compile-time diagnostics)
![Rust errors A](../screenshots/rust-errors_a.png)
![Rust errors B](../screenshots/rust-errors_b.png)

| Test | Error | Explanation |
|---|---|---|
| `5 + "3"` | E0277 | Integer and string slice cannot be added. |
| `v = "hello"` after integer initialization | E0308 | Incompatible assignment to integer variable. |
| `add_one("a")` | E0308 | Function expects `i32`, not `&str`. |
| `5 + 2.5` | E0277 | Mixing inferred integer and floating-point values in this operation is unsupported. |

### `main.rs` (corrected program)
![Rust results](../screenshots/rust-results.png)

The program parses `"3"` as `i32` to produce `8`, reassigns the mutable integer from `10` to `20`, calls `add_one(4)` to produce `5`, and casts the integer to `f64` before adding `2.5` to produce `7.5`.

## Observations
The invalid examples are rejected *before execution*, while valid explicit conversions compile. Rust cannot prevent every runtime failure: `.parse().unwrap()` can panic if parsing fails. The examples distinguish compiler diagnostics from runtime behavior.
