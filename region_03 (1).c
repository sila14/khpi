#include <stdio.h>
#include <stdbool.h>
#include <math.h>

/*
 * Lab 04_03 (Variant 03)
 * From the picture: parabola y = x^2 - 1 and a diamond with vertices (-1,0), (0,1), (1,0), (0,-1).
 * The shaded region is the curved strip between:
 *   lower diamond edge: y = |x| - 1   (for -1 <= x <= 1)
 *   parabola:          y = x^2 - 1
 * Predicate (with EPS):
 *   -1 <= x <= 1  AND  x^2 - 1 <= y <= |x| - 1
 */

int main(void) {
    const double EPS = 1e-9;
    double x, y;

    printf("Enter x y: ");
    if (scanf("%lf %lf", &x, &y) != 2) {
        puts("Input error");
        return 1;
    }

    double y_par = x * x - 1.0;       /* y = x^2 - 1 */
    double y_v   = fabs(x) - 1.0;     /* y = |x| - 1 */

    bool in_x_range = (x >= -1.0 - EPS) && (x <=  1.0 + EPS);
    bool above_par  = (y >= y_par - EPS);
    bool below_v    = (y <= y_v + EPS);

    bool inside = in_x_range && above_par && below_v;

    /* Optional: print intermediate checks (useful for debugging) */
    printf("y_par=%.6f, y_v=%.6f\n", y_par, y_v);
    printf("in_x_range=%d, above_par=%d, below_v=%d\n",
           in_x_range ? 1 : 0, above_par ? 1 : 0, below_v ? 1 : 0);

    puts(inside ? "YES" : "NO");

    return 0;
}
