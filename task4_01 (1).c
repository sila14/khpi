#include <stdio.h>

/*
 * Lab 04_01 (Variant 3)
 * Task: For positive integers a, b, check whether a mod b equals either of the given values c or d.
 * Notes: no loops, no arrays, no user functions.
 */

int main(void) {
    int a, b, c, d;

    printf("Enter a, b, c, d (positive integers): ");
    if (scanf("%d %d %d %d", &a, &b, &c, &d) != 4) {
        puts("Input error");
        return 1;
    }

    if (a <= 0 || b <= 0) {
        puts("Error: a and b must be positive and b must be non-zero.");
        return 2;
    }

    int r = a % b;

    printf("a mod b = %d\n", r);

    if (r == c || r == d) {
        puts("YES (remainder equals c or d)");
    } else {
        puts("NO (remainder is different)");
    }

    /* Ternary operator demo (same decision) */
    puts((r == c || r == d) ? "Ternary: YES" : "Ternary: NO");

    return 0;
}
