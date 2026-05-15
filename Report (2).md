# Lab work #3 — Expressions (C)

Student: **Sıla Canbolat**  
Group: **КН-925і.е**  
Course: Programming. Part 1 (NTU “KhPI”)  
Lab: **03_01 (Arithmetic Expressions)** and **03_02 (Trig/Exp/Log Expressions)**

---

## What I did (workflow)

I did check my variant number in the lab document and I selected **Variant 3** for both subtasks.  
Afterwards, I created two separate Git branches: `lab03_01` and `lab03_02` (one branch per task).  
After that, I created two separate source files: `task3_1.c` and `task3_2.c` (one file per subtask).  
Afterwards, I calculated all intermediate parts in separate variables (a, b, c, d, e) so I could inspect them easily in GDB.  
Finally, I tested the programs with normal values, near-boundary values, and undefined values to demonstrate the domain restrictions.

---

## Lab 03_01 — Arithmetic Expressions

### Variant 3 formula
E(x) = (2x − 1)/(x^2 − 1) + ((x − 5)(x + 2))/(3x + 6)

### Domain of definition (DOD)
Denominators must be non-zero:
- x^2 − 1 ≠ 0  →  x ≠ 1 and x ≠ −1  
- 3x + 6 ≠ 0  →  x ≠ −2

So: **DOD = ℝ \ {-2, -1, 1}**

### Compilation
```bash
gcc -g -O0 -Wall task3_1.c -o task3_1
```

### Sample runs (3 different values)
The program prints `E(x)` with 8 digits after the decimal point.

| x | E(x) |
|---:|---:|
| 0.000000 | -0.66666667 |
| 2.000000 | 0.00000000 |
| 0.999000 (near x=1) | -500.58329148 |

### Undefined input demo
- If `x = 1` or `x = -1` then `x^2 − 1 = 0`
- If `x = -2` then `3x + 6 = 0`

In these cases I did print an **“undefined”** message without dividing.

### Debug session (GDB transcript example)
```text
gcc -g -O0 -Wall task3_1.c -o task3_1
gdb ./task3_1
(gdb) break main
(gdb) run
Enter x: 0.999
(gdb) next
(gdb) print a
(gdb) next
(gdb) print b
(gdb) next
(gdb) print c
(gdb) next
(gdb) print d
(gdb) next
(gdb) print E
(gdb) run
Enter x: 1
```

---

## Lab 03_02 — Expressions with Trig/Exp/Log

### Variant 3 formula
E(x) = sin(2x)/(cos x − 1) + (log10(x + 5) · exp(−x))/(x + 2)

### Domain of definition (DOD)
I did define the domain by checking every restriction:
- log10(x + 5) requires **x + 5 > 0** → **x > −5**
- denominator (x + 2) ≠ 0 → **x ≠ −2**
- denominator (cos x − 1) ≠ 0 → cos x ≠ 1 → **x ≠ 2kπ**, where k ∈ ℤ

So:
**DOD = { x ∈ ℝ | x > −5, x ≠ −2, and x ≠ 2kπ }**

### Compilation (with math library)
```bash
gcc -g -O0 -Wall task3_2.c -o task3_2 -lm
```

### Sample runs (normal + near singularity + near boundary)
| x | E(x) |
|---:|---:|
| 0.500000 | -6.69416258 |
| 0.001000 (near x=0 where cos(x)-1→0) | -3999.64866216 |
| -4.900000 (near x=-5 boundary) | 45.85631695 |

### Undefined input demo
Afterwards, I tested invalid cases and printed a clear message:
- `x = 0` → cos(0) − 1 = 0 (division by zero)
- `x = -2` → x + 2 = 0 (division by zero)
- `x ≤ -5` → log10(x + 5) argument is not positive

### Debug session (GDB transcript example)
```text
gcc -g -O0 -Wall task3_2.c -o task3_2 -lm
gdb ./task3_2
(gdb) break main
(gdb) run
Enter x: 0.5
(gdb) next
(gdb) print a
(gdb) next
(gdb) print b
(gdb) next
(gdb) print c
(gdb) next
(gdb) print d
(gdb) next
(gdb) print e
(gdb) next
(gdb) print E
```

---

## Files to submit
- `task3_1.c`
- `task3_2.c`
- `Report.md`

---

## References
1. Lab 03_01 — Arithmetic Expressions (NTU “KhPI”, Programming. Part 1, 2025/26).  
2. Lab 03_02 — Expressions with Trig/Exponential/Log (NTU “KhPI”, Programming. Part 1, 2025/26).
