#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <float.h>
#include "solve.h"

int are_doubles_equal(const double num1, const double num2) {
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

    if (are_doubles_equal(number, 0)) {
        return 0;
    }
    else {
        return number;
    }
}

void swap_numbers(double * const num1_ptr, double * const num2_ptr) {
    double temp = *num1_ptr;
    *num1_ptr = *num2_ptr;
    *num2_ptr = temp;
}

int solve(const double a, const double b, const double c, double * const x1ptr, double * const x2ptr) {
    assert(isfinite(a) && !isnan(a));
    assert(isfinite(b) && !isnan(b));
    assert(isfinite(c) && !isnan(c));
    assert(x1ptr != NULL);
    assert(x2ptr != NULL);

    if (are_doubles_equal(a, 0)) {  // linear equations
        return solve_linear(b, c, x1ptr);
    }
    else {
        if (are_doubles_equal(c, 0) && are_doubles_equal(b, 0)) {  // equations ax^2 = 0
            *x1ptr = 0;
            return 1;
        }
        else if (are_doubles_equal(c, 0) && !are_doubles_equal(b, 0)) {  // equations ax^2 + bx = 0
            *x1ptr = - b / a;
            if (*x1ptr > 0) {
                swap_numbers(x1ptr, x2ptr);
            }
            return 2;
        }
        else {  // standart square equations with non-zero coefficients
            double discrim = b * b - 4 * a * c;

            if (are_doubles_equal(discrim, 0)) {  // discriminant is zero, one solution
                *x1ptr = - b / (2 * a);
                return 1;
            }
            else if (discrim < 0) {  // discriminant is less than zero, no solutions
                return 0;
            }
            else {  // discriminant is more than zero, 2 solutions
                double d_root = sqrt(discrim);

                *x1ptr = (-b - d_root) / (2 * a);
                *x2ptr = (-b + d_root) / (2 * a);

                return 2;
            }
        }
    }
}


int solve_linear(const double b, const double c, double * const x1ptr) {
    assert(isfinite(b) && !isnan(b));
    assert(isfinite(c) && !isnan(c));
    assert(x1ptr != NULL);

    if (are_doubles_equal(b, 0) && are_doubles_equal(c, 0)) {
        return INF_ROOTS;
    }
    else if (are_doubles_equal(b, 0) && !are_doubles_equal(c, 0)) {
        return 0;
    }
    else {
        *x1ptr = - c / b;
        return 1;
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
