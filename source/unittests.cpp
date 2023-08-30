#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <string.h>
#include "./headers/solve.h"
#include "./headers/output.h"
#include "./headers/unittests.h"
#include "./headers/roots_amount.h"

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

    unsigned int tests_amount = (sizeof test_list) / (sizeof (TestReference));

    for (unsigned int i = 0; i < tests_amount; i++) {
        printf("Test %d: ", i + 1);
        success_tests += run_one_test(&test_list[i]);
    }

    return success_tests;
}

int read_tests_from_file(const char* const input_filename) {
    assert(input_filename != NULL);

    int success_tests = 0;

    FILE* input_file = fopen(input_filename, "r");

    TestReference current_test = {0};

    char raw_roots_amount[MAX_NAME_LEN] = "";

    int test_number = 1;

    while (fscanf(input_file, "%lg %lg %lg %lg %lg %s %s",
           &current_test.a, &current_test.b, &current_test.c,
           &current_test.x1ref, &current_test.x2ref,
           raw_roots_amount, &current_test.test_name) == 7 &&
           get_root_amount_ref(raw_roots_amount, &current_test.amount_ref)) {
        printf("Test %d: ", test_number++);
        success_tests += run_one_test(&current_test);
    }

    return success_tests;
}

static bool get_root_amount_ref(const char* const raw_amount, int* const amount) {
    if (strcmp(raw_amount, "NO_ROOTS") == 0 || strcmp(raw_amount, "0") == 0) {
        *amount = NO_ROOTS;
        return 1;
    }
    else if (strcmp(raw_amount, "ONE_ROOT") == 0 || strcmp(raw_amount, "1") == 0) {
        *amount = ONE_ROOT;
        return 1;
    }
    else if (strcmp(raw_amount, "TWO_ROOTS") == 0 || strcmp(raw_amount, "2") == 0) {
        *amount = TWO_ROOTS;
        return 1;
    }
    else if (strcmp(raw_amount, "INF_ROOTS") == 0) {
        *amount = INF_ROOTS;
        return 1;
    }
    else {
        return 0;
    }
}

static int run_one_test(const TestReference* const current_test) {
    assert(current_test != NULL);
    assert(current_test->test_name != NULL);
    assert(isfinite(current_test->a));
    assert(isfinite(current_test->b));
    assert(isfinite(current_test->c));
    assert(isfinite(current_test->x1ref));
    assert(isfinite(current_test->x2ref));

    double x1 = 0;
    double x2 = 0;

    int amount = solve_equation(current_test->a, current_test->b, current_test->c, &x1, &x2);

    if (check_test_output(x1, x2, amount, current_test)) {
        printf("OK\n");
        return 1;
    }
    else {
        Roots received_roots = {{x1, x2}, amount};
        Roots excepted_roots = {{current_test->x1ref, current_test->x2ref}, current_test->amount_ref};

        printf("ERROR in %s!\n"
               "\tCoefficients: a = %f, b = %f, c = %f\n"
               "\tReceived: ", current_test->test_name,
               current_test->a, current_test->b, current_test->c);
        print_solutions(&received_roots);
        printf("\tExcepted: ");
        print_solutions(&excepted_roots);
        return 0;
    }
}

static bool check_test_output(const double x1, const double x2, const int amount,
                              const TestReference* const current_test) {
    return (are_doubles_equal(x1, current_test->x1ref) &&
            are_doubles_equal(x2, current_test->x2ref) &&
            amount == current_test->amount_ref);
}
