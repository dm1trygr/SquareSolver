#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "solve.h"
#include "unittests.h"

int run_tests(void) {
    int success_tests = 0;

    TestReference test_list[] = {
//       a   b   c  x1  x2     amount  name
        {0,  0,  0,  0,  0, INF_ROOTS, "ZeroTest"},
        {1,  2,  1, -1,  0,         1, "OneRootTest1"},
        {1, -2,  1,  1,  0,         1, "OneRootTest2"},
        {1,  0,  4,  0,  0,         0, "ZeroSolutionsTest"},
        {1,  0, -4, -2,  2,         2, "SquareVarTest"},
        {0,  2, -4,  2,  0,         1, "LinearTest"},
        {1,  5,  4, -4, -1,         2, "RandomTest"}
    };

    for (int i = 0; i < (sizeof test_list) / (sizeof (TestReference)); i++) {
        printf("Test %d: ", i + 1);
        success_tests += run_one_test(&test_list[i]);  //run_one_trst
    }

    return success_tests;
}

int run_one_test(const TestReference * const current_test) {
    assert(current_test != NULL);
    assert(current_test->test_name != NULL);
    assert(isfinite(current_test->a) && ! isnan(current_test->a));
    assert(isfinite(current_test->b) && ! isnan(current_test->b));
    assert(isfinite(current_test->c) && ! isnan(current_test->c));
    assert(isfinite(current_test->x1ref) && ! isnan(current_test->x1ref));
    assert(isfinite(current_test->x2ref) && ! isnan(current_test->x2ref));

    double x1 = 0;
    double x2 = 0;

    int amount = solve(current_test->a, current_test->b, current_test->c, &x1, &x2);

    if (are_doubles_equal(x1, current_test->x1ref) &&
        are_doubles_equal(x2, current_test->x2ref) &&
        amount == current_test->amount_ref) {  // в отдельнуб функцию проверку значений
        printf("OK\n");
        return 1;
    }
    else {
        printf("ERROR in %s!\n"
               "\tCoefficients: a = %f, b = %f, c = %f\n"
               "\tReceived: amount = %d, x1 = %f, x2 = %f\n"
               "\tExcepted: amount = %d, x1 = %f, x2 = %f\n",
               current_test->test_name,
               current_test->a, current_test->b, current_test->c,
               amount, x1, x2,
               current_test->amount_ref,
               current_test->x1ref, current_test->x2ref);
        return 0;
    }
}
