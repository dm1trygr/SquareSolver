#include <cstdio>  // это вместо stdio.h
#include <assert.h>
#include <math.h>
#include <float.h>
#include "solve.h"
#include "roots_amount.h"

int are_doubles_equal(const double num1, const double num2) {  // в плюсах отдельный инклюд для bool не нужен
    assert(isfinite(num1)); // аналогично убрать isnan()
    assert(isfinite(num2));

    return fabs(num1 - num2) <= DBL_EPSILON;
}   // сделать частный случай - сравнение с нулем

double round_to_zero(const double number) {
    assert(isfinite(number));

    if (are_doubles_equal(number, 0)) {
        return 0;
    }
    return number;
}

void swap_numbers(double * const num1_ptr, double * const num2_ptr) {
    assert(num1_ptr != NULL);
    assert(num2_ptr != NULL);

    double temp = *num1_ptr;
    *num1_ptr = *num2_ptr;
    *num2_ptr = temp;
}

int solve(const double a, const double b, const double c,
          double * const x1ptr, double * const x2ptr) {
    assert(isfinite(a));            // rename to solve_equation
    assert(isfinite(b));
    assert(isfinite(c));
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
    assert(isfinite(b));
    assert(isfinite(c));
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
