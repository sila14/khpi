#include <stdio.h>
#include <math.h>

/*
 * Lab 03_02 — Trig/Exp/Log Expressions (Variant 3)
 * E(x) = sin(2x)/(cos x - 1) + (log10(x + 5) * exp(-x))/(x + 2)
 *
 * Notes:
 * - No loops, no arrays, no user-defined functions.
 * - Compile and link with: gcc -g -O0 -Wall task3_2.c -o task3_2 -lm
 */

int main(void) {
    double x;
    printf("Enter x: ");
    if (scanf("%lf", &x) != 1) {
        printf("Input error.\n");
        return 1;
    }

    /* Domain checks */
    if (x + 5.0 <= 0.0) {
        printf("E(x) is undefined because log10(x + 5) requires (x + 5) > 0.\n");
        printf("x + 5 = %.10f\n", x + 5.0);
        return 0;
    }

    double b = cos(x) - 1.0;   /* denominator #1 */
    double e = x + 2.0;        /* denominator #2 */

    if (fabs(b) < 1e-12) {
        printf("E(x) is undefined because cos(x) - 1 is (almost) zero.\n");
        printf("cos(x) - 1 = %.16f\n", b);
        return 0;
    }
    if (fabs(e) < 1e-12) {
        printf("E(x) is undefined because x + 2 is (almost) zero.\n");
        printf("x + 2 = %.16f\n", e);
        return 0;
    }

    /* Compute parts separately for easier GDB inspection */
    double a = sin(2.0 * x);
    double c = log10(x + 5.0);
    double d = exp(-x);

    double E = a / b + (c * d) / e;
    printf("E(%.6f) = %.8f\n", x, E);

    return 0;
}
