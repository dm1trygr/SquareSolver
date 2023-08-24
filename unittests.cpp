#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "solve.h"
#include "unittests.h"

int run_tests(void) {
    int success_tests = 0;

    success_tests += do_one_test(0, 0, 0, 0, 0, INF_ROOTS);
    success_tests += do_one_test(1, 2, 1, -1, 0, 1);
    success_tests += do_one_test(1, -2, 1, 1, 0, 1);
    success_tests += do_one_test(1, 0, 4, 0, 0, 0);
    success_tests += do_one_test(1, 0, -4, -2, 2, 2);
    success_tests += do_one_test(0, 2, -4, 2, 0, 1);
    success_tests += do_one_test(1, 5, 4, -4, -1, 2);

    return success_tests;
}

int do_one_test(const double a, const double b, const double c,const double x1ref, const double x2ref,
            const int amount_ref) {
    assert(isfinite(a) && !isnan(a));
    assert(isfinite(b) && !isnan(b));
    assert(isfinite(c) && !isnan(c));
    assert(isfinite(x1ref) && !isnan(x1ref));
    assert(isfinite(x2ref) && !isnan(x2ref));
    assert(isfinite(amount_ref) && !isnan(amount_ref));

    static int test_number = 1;

    double x1 = 0, x2 = 0;
    int roots_amt = 0;

    roots_amt = solve(a, b, c, &x1, &x2);

    if (is_doubles_equal(x1, x1ref) && is_doubles_equal(x2, x2ref) && roots_amt == amount_ref) {
        printf("Test %2d: a = %.3f, b = %.3f, c = %.3f: OK\n", test_number++, a, b, c);
        return 1;
    }
    else {
        printf("Test %2d: a = %.3f, b = %.3f, c = %.3f: ERROR: Received x1 = %f, x2 = %f, roots_amt = %d\n"
               "                                     Excepted x1 = %f, x2 = %f, roots_amt = %d\n",
               test_number++, a, b, c, x1, x2, roots_amt, x1ref, x2ref, amount_ref);
        return 0;
    }
}
