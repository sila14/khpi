#include <stdio.h>

/*
 * Lab 03_01 — Arithmetic Expressions (Variant 3)
 * E(x) = (2x - 1)/(x^2 - 1) + ((x - 5)(x + 2))/(3x + 6)
 *
 * Notes:
 * - No loops, no arrays, no user-defined functions.
 * - Use double for calculations.
 */

int main(void) {
    double x;
    printf("Enter x: ");
    if (scanf("%lf", &x) != 1) {
        printf("Input error.\n");
        return 1;
    }

    /* Compute sub-expressions separately (good for GDB inspection) */
    double a = 2.0 * x - 1.0;
    double b = x * x - 1.0;          /* denominator #1 */
    double c = (x - 5.0) * (x + 2.0);
    double d = 3.0 * x + 6.0;        /* denominator #2 */

    /* Domain check: denominators must be non-zero */
    if (b == 0.0 || d == 0.0) {
        printf("E(x) is undefined for this x because a denominator is zero.\n");
        printf("b = x^2 - 1 = %.10f, d = 3x + 6 = %.10f\n", b, d);
        return 0;
    }

    double E = a / b + c / d;
    printf("E(%.6f) = %.8f\n", x, E);

    return 0;
}
