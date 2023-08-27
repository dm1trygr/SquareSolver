#include <cstdio>  // это вместо stdio.h
#include <assert.h>
#include <math.h>
#include <float.h>
#include "solve.h"
#include "roots_amount.h"

int are_doubles_equal(const double num1, const double num2) {  // в плюсах отдельный инклюд для bool не нужен
    assert(isfinite(num1)); // аналогично убрать isnan()
    assert(isfinite(num2) && !isnan(num2));

    return fabs(num1 - num2) <= DBL_EPSILON;
}   // сделать частный случай - сравнение с нулем

double round_to_zero(const double number) {
    assert(isfinite(number) && !isnan(number));

    if (are_doubles_equal(number, 0)) {
        return 0;
    }
    return number;
}

void swap_numbers(double * const num1_ptr, double * const num2_ptr) {
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

void print_solutions(const double roots[], const unsigned int amount) {
    // функции вывода - в отдельный файл
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

void fprint_solutions(FILE * file_pointer, const double roots[], const unsigned int amount) {
    assert(file_pointer != NULL);
    assert(roots != NULL);

    if (amount == 0) {
        fprintf(file_pointer, "No solutions\n");
    }
    else if (amount == INF_ROOTS) {
        fprintf(file_pointer, "Solution is any number\n");
    }
    else {
        fprintf(file_pointer, "(%d solutions) ", amount);
        for (int index = 0; index < amount; index++) {
            fprintf(file_pointer, "%.3f ", roots[index]);
        }
        fputc('\n', file_pointer);
    }
}
