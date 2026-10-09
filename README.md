# Type Systems Across Programming Languages

Laboratory activity for **Programming Languages**: the same small program written in four languages, each covering a different combination of static/dynamic and strong/weak typing, with each runtime documented.

## Languages

| Language | Static / Dynamic | Strong / Weak | Execution Strategy | Type errors caught |
|---|---|---|---|---|
| C | Static | Weak | AOT compiled (gcc) | Mostly never (silent conversions) |
| Rust | Static | Strong | AOT compiled (rustc) | Compile time |
| Python | Dynamic | Strong | Bytecode on a VM (CPython) | Runtime |
| JavaScript | Dynamic | Weak | JIT (V8 in Node.js) | Never (coerced) |

## The Program
Each language runs four tests:
1. Add an integer and a string/char
2. Reassign a variable to a different type
3. Call a function with the wrong argument type
4. Mix an integer and a float

## Folder Structure
```
c/            main.c, RUNTIME.md
rust/         main.rs, error.rs, RUNTIME.md
python/       main.py, RUNTIME.md
javascript/   main.js, RUNTIME.md
screenshots/  output of every run
```

## How to Run

| Language | Command |
|---|---|
| C | `gcc main.c -o main` then `.\main` |
| Rust | `rustc main.rs` then `.\main` (and `rustc error.rs` to see the compile errors) |
| Python | `python main.py` |
| JavaScript | `node main.js` |

## Key Findings
- **Static vs dynamic** decides *when* types are checked: before running (C, Rust) or while running (Python, JavaScript).
- **Strong vs weak** decides *whether* mismatched types are converted silently. C and JavaScript convert them, while Rust and Python refuse.
- Rust catches every mistake at compile time, Python catches them only when the bad line executes, and C and JavaScript let them through with altered results.

## Detailed Documentation
- [C runtime](c/RUNTIME.md)
- [Rust runtime](rust/RUNTIME.md)
- [Python runtime](python/RUNTIME.md)
- [JavaScript runtime](javascript/RUNTIME.md)

## Conclusion
The same four tests produced four different behaviors. Rust rejected them at compile time, Python rejected them at runtime, JavaScript accepted them and coerced the values, and C accepted them and silently changed the values. Static typing decides when mistakes are found, and strong typing decides whether the language lets mismatched types mix. Stricter languages like Rust trade convenience for earlier, safer error detection, while flexible languages like JavaScript trade safety for convenience.