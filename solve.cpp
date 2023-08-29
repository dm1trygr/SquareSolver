#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <float.h>
#include "./source/headers/solve.h"
#include "./source/headers/roots_amount.h"

bool are_doubles_equal(const double num1, const double num2) {
    assert(isfinite(num1));
    assert(isfinite(num2));

    return fabs(num1 - num2) <= DBL_EPSILON;
}

bool is_equal_to_zero(const double number) {
    assert(isfinite(number));

    return are_doubles_equal(number, 0);
}

double round_to_zero(const double number) {
    assert(isfinite(number));

    if (is_equal_to_zero(number)) {
        return 0;
    }
    return number;
}

void swap_numbers(double* const num1_ptr, double* const num2_ptr) {
    assert(num1_ptr != NULL);        // область видимости в пределах файла
    assert(num2_ptr != NULL);

    double temp = *num1_ptr;
    *num1_ptr = *num2_ptr;
    *num2_ptr = temp;
}

int solve_equation(const double a, const double b, const double c,
                   double* const x1ptr, double* const x2ptr) {
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));
    assert(x1ptr != NULL);
    assert(x2ptr != NULL);

    if (is_equal_to_zero(a)) {  // linear equations
        return solve_linear(b, c, x1ptr);
    }
    else {
        if (is_equal_to_zero(c) && is_equal_to_zero(b)) {  // equations ax^2 = 0
            *x1ptr = 0;
            return ONE_ROOT;
        }
        else if (is_equal_to_zero(c) && !is_equal_to_zero(b)) {  // equations ax^2 + bx = 0
            *x1ptr = - b / a;
            *x2ptr = 0;

            if (*x1ptr > 0) {
                swap_numbers(x1ptr, x2ptr);
            }

            return TWO_ROOTS;
        }
        else {  // standart square equations with non-zero coefficients
            double discrim = b * b - 4 * a * c;

            if (is_equal_to_zero(discrim)) {  // discriminant is zero, one solution
                *x1ptr = - b / (2 * a);
                return ONE_ROOT;
            }
            else if (discrim < 0) {  // discriminant is less than zero, no solutions
                return NO_ROOTS;
            }
            else {  // discriminant is more than zero, 2 solutions
                double d_root = sqrt(discrim);

                *x1ptr = (-b - d_root) / (2 * a);
                *x2ptr = (-b + d_root) / (2 * a);

                return TWO_ROOTS;
            }
        }
    }
}


int solve_linear(const double b, const double c, double* const x1ptr) {
    assert(isfinite(b));
    assert(isfinite(c));
    assert(x1ptr != NULL);

    if (is_equal_to_zero(b) && is_equal_to_zero(c)) {
        return INF_ROOTS;
    }
    else if (is_equal_to_zero(b) && !is_equal_to_zero(c)) {
        return 0;
    }
    else {
        *x1ptr = - c / b;
        return 1;
    }
}
