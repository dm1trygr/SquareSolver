#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <float.h>
#include "square_solver.h"

int is_doubles_equal(const double num1, const double num2) {
    assert(isfinite(num1) && !isnan(num2));
    assert(isfinite(num1) && !isnan(num2));

    if (fabs(num1 - num2) <= DBL_EPSILON) {
        return 1;
    }
    else {
        return 0;
    }
}

int solve(const double a, const double b, const double c, double * const x1ptr, double * const x2ptr) {
    assert(isfinite(a) && !isnan(a));
    assert(isfinite(b) && !isnan(b));
    assert(isfinite(c) && !isnan(c));
    assert(x1ptr != NULL);
    assert(x2ptr != NULL);

    if (is_doubles_equal(a, 0)) {
        return linear(b, c, x1ptr);
    }
    else {
        return square(a, b, c, x1ptr, x2ptr);
    }
}

int linear(const double b, const double c, double * const x1ptr) {
    assert(isfinite(b) && !isnan(b));
    assert(isfinite(c) && !isnan(c));
    assert(x1ptr != NULL);

    if (is_doubles_equal(b, 0) && is_doubles_equal(c, 0)) {
        return INF_ROOTS;
    }
    else if (is_doubles_equal(b, 0) && !is_doubles_equal(c, 0)) {
        return 0;
    }
    else {
        *x1ptr = - c / b;
        return 1;
    }
}

int square(const double a, const double b, const double c, double * const x1ptr, double * const x2ptr) {
    assert(isfinite(a) && !isnan(a));
    assert(isfinite(b) && !isnan(b));
    assert(isfinite(c) && !isnan(c));
    assert(x1ptr != NULL);
    assert(x2ptr != NULL);

    double discrim = b * b - 4 * a * c;

    if (is_doubles_equal(discrim, 0)) {
        *x1ptr = - b / (2 * a);
        return 1;
    }
    else if (discrim < 0) {
        return 0;
    }
    else {
        double d_root = sqrt(discrim);
        *x1ptr = (-b - d_root) / (2 * a);
        *x2ptr = (-b + d_root) / (2 * a);
        return 2;
    }
}

void print_solutions(const int roots_amount, const double x1, const double x2) {
    assert((roots_amount <= 2 && roots_amount >= 0) || roots_amount == INF_ROOTS);
    assert(isfinite(roots_amount) && !isnan(roots_amount));
    assert(isfinite(x1) && !isnan(x1));
    assert(isfinite(x2) && !isnan(x2));


    switch (roots_amount) {
        case 0:
            printf("There is no solutions\n");
            break;
        case 1:
            printf("There is 1 solution: %.3f\n", round_to_zero(x1));
            break;
        case 2:
            printf("There is 2 solutions: %.3f and %.3f\n", round_to_zero(x1), round_to_zero(x2));
            break;
        case INF_ROOTS:
            printf("The solution is any number\n");
            break;
        default:
            printf("Error in roots_amount!\n");
    }
}

double round_to_zero(const double number) {
    assert(isfinite(number) && !isnan(number));

    if (is_doubles_equal(number, 0)) {
        return 0;
    }
    else {
        return number;
    }
}
