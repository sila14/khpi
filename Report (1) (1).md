# Lab Work #4 — Conditional Statements (C)

**Student:** Sıla Canbolat  
**Group:** КН-925і.е  
**Institute:** ННІ КНІТ  
**Discipline:** Programming. Part 1 (C)  
**Variant:** 3

---

## Part 04_01 — if / else (Variant 3)

**Task statement:** For positive integers `a, b`, check whether `a mod b` equals either of the given values `c` or `d`.

### I did (algorithm)
1. I did read integers `a, b, c, d` from the console.
2. Afterwards, I validated that `a > 0` and `b > 0` (to avoid division by zero).
3. After that, I computed `r = a % b`.
4. Finally, I compared `r` with `c` and `d` and printed `YES` or `NO` (also a ternary demo).

### Build & run
```bash
gcc -Wall -Wextra -O0 -g task4_01.c -o task4_01
./task4_01
```

### Sample outputs (3 tests)
**Test 1**
```
Input:  17 5 2 3
a mod b = 2
YES (remainder equals c or d)
Ternary: YES
```

**Test 2**
```
Input:  25 7 1 4
a mod b = 4
YES (remainder equals c or d)
Ternary: YES
```

**Test 3**
```
Input:  30 6 1 5
a mod b = 0
NO (remainder is different)
Ternary: NO
```

### Debug session (GDB, 10–20 lines)
```text
gdb ./task4_01
(gdb) break main
(gdb) run
Enter a, b, c, d (positive integers): 17 5 2 3
(gdb) next
(gdb) print a
$1 = 17
(gdb) print b
$2 = 5
(gdb) next
(gdb) print r
$3 = 2
(gdb) next
(gdb) continue
```

---

## Part 04_02 — switch / case (Variant 3)

**Task statement:** Traffic light. Input color code **(1–red, 2–yellow, 3–green)** and print the corresponding action.

### I did (algorithm)
1. I did read the integer code from the console.
2. Afterwards, I used one `switch` statement with `case` blocks and `break`.
3. After that, I printed the action for each valid code.
4. Finally, I handled invalid codes with `default`.

### Build & run
```bash
gcc -Wall -Wextra -O0 -g task4_02.c -o task4_02
./task4_02
```

### Sample outputs (3 tests)
**Test 1**
```
Input: 1
RED: STOP
```

**Test 2**
```
Input: 2
YELLOW: WAIT / PREPARE
```

**Test 3**
```
Input: 9
Error: code must be 1, 2, or 3
```

### Debug session (GDB, 10–20 lines)
```text
gdb ./task4_02
(gdb) break main
(gdb) run
Enter traffic light code (1=red, 2=yellow, 3=green): 2
(gdb) next
(gdb) print code
$1 = 2
(gdb) next
(gdb) continue
```

---

## Part 04_03 — Point in Region (Variant 03)

### Boundaries and equations (from the picture)
- Parabola: **y = x^2 - 1**
- Lower diamond edges:
  - left:  y = -x - 1 (for -1 ≤ x ≤ 0)
  - right: y =  x - 1 (for  0 ≤ x ≤ 1)
  - compact: **y = |x| - 1** (for -1 ≤ x ≤ 1)

### Final logical condition (predicate)
A point `(x, y)` is inside the shaded region if:
- **-1 ≤ x ≤ 1**
- **x^2 - 1 ≤ y ≤ |x| - 1**

### I did (algorithm)
1. I did read `x` and `y` as `double`.
2. Afterwards, I computed `y_par = x^2 - 1` and `y_v = |x| - 1`.
3. After that, I checked the three logical parts: `in_x_range`, `above_par`, `below_v`.
4. Finally, I printed `YES` if all conditions were true, otherwise `NO`.

### Build & run (note `-lm`)
```bash
gcc -Wall -Wextra -O0 -g region_03.c -lm -o region_03
./region_03
```

### Test points (5–8) with expected answers
| # | x | y | Expected |
|---:|---:|---:|:---:|
| 1 | 0.5 | -0.6 | YES |
| 2 | -0.5 | -0.6 | YES |
| 3 | 0.5 | -0.9 | NO  |
| 4 | 0.5 | -0.4 | NO  |
| 5 | 1.0 | 0.0 | YES |
| 6 | 0.0 | -1.0 | YES |
| 7 | 0.0 | 0.0 | NO  |

### Debug session (GDB, 10–20 lines)
```text
gdb ./region_03
(gdb) break main
(gdb) run
Enter x y: 0.5 -0.6
(gdb) next
(gdb) print x
$1 = 0.5
(gdb) print y
$2 = -0.6
(gdb) next
(gdb) print y_par
$3 = -0.75
(gdb) print y_v
$4 = -0.5
(gdb) print inside
$5 = true
(gdb) continue
```

---

## References
1. Markdown Guide — Basic Syntax: https://www.markdownguide.org/basic-syntax/  
2. VS Code: https://code.visualstudio.com/  
3. Lab 04_01 — Conditional Statements (C), Volodymyr Savchenko, NTU “KhPI”, 2025/26.  
4. Lab 04_02 — switch...case Structures (C), Volodymyr Savchenko, NTU “KhPI”, 2025/26.  
5. Lab 04_03 — Point-in-Region Tests (C), Volodymyr Savchenko, NTU “KhPI”, 2025/26.
