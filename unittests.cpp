#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "square_solver.h"

int runtests(void) {
    int success_tests = 0;

    success_tests += onetest(0, 0, 0, 0, 0, INF_ROOTS);
    success_tests += onetest(1, 2, 1, -1, 0, 1);
    success_tests += onetest(1, -2, 1, 1, 0, 1);
    success_tests += onetest(1, 0, 4, 0, 0, 0);
    success_tests += onetest(1, 0, -4, -2, 2, 2);
    success_tests += onetest(0, 2, -4, 2, 0, 1);
    success_tests += onetest(1, 5, 4, -4, -1, 2);

    return success_tests;
}

int onetest(const double a, const double b, const double c, const double x1ref, const double x2ref, const int amtref) {
    assert(isfinite(a) && !isnan(a));
    assert(isfinite(b) && !isnan(b));
    assert(isfinite(c) && !isnan(c));
    assert(isfinite(x1ref) && !isnan(x1ref));
    assert(isfinite(x2ref) && !isnan(x2ref));
    assert(isfinite(amtref) && !isnan(amtref));

    double x1 = 0, x2 = 0;
    int roots_amt = 0;

    roots_amt = solve(a, b, c, &x1, &x2);

    if (is_doubles_equal(x1, x1ref) && is_doubles_equal(x2, x2ref) && roots_amt == amtref) {
        printf("a = %.3f, b = %.3f, c = %.3f: OK\n", a, b, c);
        return 1;
    }
    else {
        printf("a = %.3f, b = %.3f, c = %.3f: ERROR: Received x1 = %f, x2 = %f, roots_amt = %d\n"
               "                                     Excepted x1 = %f, x2 = %f, roots_amt = %d\n",
               a, b, c, x1, x2, roots_amt, x1ref, x2ref, amtref);
        return 0;
    }
}
