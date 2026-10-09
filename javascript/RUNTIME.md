# JavaScript Runtime Documentation

## Environment
- Version: [output of `node --version`]
- Run command: `node main.js`

## Type System
- **Dynamic:** types belong to values, and `let v` can hold a number and then a string (test 2).
- **Weak:** the engine silently coerces types instead of failing. `5 + "3"` becomes the string `"53"`, while `5 - "3"` becomes the number `2`.

## Execution Strategy
Node.js runs on the **V8 engine**, which parses the code, interprets it with a bytecode interpreter, and **JIT-compiles** hot code paths to machine code while the program runs.

## Results
![JavaScript results](../screenshots/javascript-results.png)

| Test | Result | Caught when? |
|---|---|---|
| 1. `5 + "3"` / `5 - "3"` | `"53"` / `2` | Never (coerced) |
| 2. Reassign number to string | Allowed | n/a |
| 3. `addOne("a")` | `"a1"` | Never (coerced) |
| 4. `5 + 2.5` | `7.5` | n/a |

## Observations
No test produced an error. `5 + "3"` returned the string `"53"`, while `5 - "3"` returned the number `2`, so the same operand types behaved differently depending on the operator. `addOne("a")` returned `"a1"` instead of failing. This is weak typing: JavaScript coerces values silently. The danger is that bugs show up as wrong output rather than as errors. Reassigning `v` from a number to a string also worked, since types belong to values, not variables.