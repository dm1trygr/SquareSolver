#include <stdio.h>
#include <math.h>
#include <float.h>
#include "func_header.h"

int is_zero(const double number) {
    if (fabs(number) <= DBL_EPSILON) {
        return 1;
    }
    else {
        return 0;
    }
}

int solve(const double a, const double b, const double c, double * const x1ptr, double * const x2ptr) {
    if (is_zero(a)) {
        return linear(b, c, x1ptr);
    }
    else {
        return square(a, b, c, x1ptr, x2ptr);
    }
}

int linear(const double b, const double c, double * const x1ptr) {
    if (is_zero(b) && is_zero(c)) {
        return INF_ROOTS;
    }
    else if (is_zero(b) && !is_zero(c)) {
        return 0;
    }
    else {
        *x1ptr = - c / b;
        return 1;
    }
}

int square(const double a, const double b, const double c, double * const x1ptr, double * const x2ptr) {
    double discrim = b * b - 4 * a * c;

    if (is_zero(discrim)) {
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
    switch (roots_amount) {
        case 0:
            printf("There is no solutions\n");
            break;
        case 1:
            printf("There is 1 solution: %.3f\n", x1);
            break;
        case 2:
            printf("There is 2 solutions: %.3f and %.3f\n", x1, x2);
            break;
        case INF_ROOTS:
            printf("The solution is any number\n");
            break;
        default:
            printf("Error in roots_amount!\n");
    }
}
