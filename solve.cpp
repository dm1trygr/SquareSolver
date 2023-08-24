#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <float.h>
#include "solve.h"

int is_doubles_equal(const double num1, const double num2) {
    assert(isfinite(num1) && !isnan(num1));
    assert(isfinite(num2) && !isnan(num2));

    if (fabs(num1 - num2) <= DBL_EPSILON) {
        return 1;
    }
    else {
        return 0;
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

int solve(const double a, const double b, const double c, double * const x1ptr, double * const x2ptr) {
    assert(isfinite(a) && !isnan(a));
    assert(isfinite(b) && !isnan(b));
    assert(isfinite(c) && !isnan(c));
    assert(x1ptr != NULL);
    assert(x2ptr != NULL);

    if (is_doubles_equal(a, 0)) {
        return solve_linear(b, c, x1ptr);
    }
    else {
        return solve_square(a, b, c, x1ptr, x2ptr);
    }
}


int solve_linear(const double b, const double c, double * const x1ptr) {
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

int solve_square(const double a, const double b, const double c, double * const x1ptr, double * const x2ptr) {
    assert(isfinite(a) && !isnan(a) && !is_doubles_equal(a, 0));
    assert(isfinite(b) && !isnan(b));
    assert(isfinite(c) && !isnan(c));
    assert(x1ptr != NULL);
    assert(x2ptr != NULL);

    if (is_doubles_equal(c, 0) && is_doubles_equal(b, 0)) {
        *x1ptr = 0;
        return 1;
    }
    else if (is_doubles_equal(c, 0) && !is_doubles_equal(b, 0)) {
        double temp = - b / a;
        if (temp < 0) {
            *x1ptr = temp;
            *x2ptr = 0;
        }
        else {
            *x1ptr = 0;
            *x2ptr = temp;
        }
        return 2;
    }
    else {
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
}

void print_solutions(const double roots[], const int amount) {
    assert(amount >= 0);
    assert(roots != NULL);

    if (amount == 0) {
        printf("There is no solutions\n");
    }
    else if (amount == INF_ROOTS) {
        printf("The solution is any number\n");
    }
    else {
        printf("Amount of roots: %d\n"
               "Roots: ", amount);
        for (int i = 0; i < amount; i++) {
            assert(isfinite(roots[i]) && !isnan(roots[i]));
            printf("%.3f ", roots[i]);
        }
        putchar('\n');
    }
}
