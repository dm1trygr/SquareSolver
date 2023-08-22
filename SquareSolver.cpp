#include <stdio.h>
#include <math.h>
#include <float.h>

const int INF_ROOTS = 3;

double coeff_input(void);
int is_zero(const double number);
int solve(const double a, const double b, const double c, double * const x1ptr, double * const x2ptr);
int linear(const double b, const double c, double * const x1ptr);
int square(const double a, const double b, const double c, double * const x1ptr, double * const x2ptr);

int main(void) {
    printf("Welcome to Square equation solver\n"
           "This program can solve square equations\n\n");

    double a = 0, b = 0, c = 0;

    printf("Enter first number (a):\n");
    a = coeff_input();

    printf("Now enter second number (b):\n");
    b = coeff_input();

    printf("And finally, enter third number (c):\n");
    c = coeff_input();

    double x1 = 0, x2 = 0;
    int roots_amount = solve(a, b, c, &x1, &x2);

    switch (roots_amount) {
        case 0:
            printf("There is no solutions\n");
            break;
        case 1:
            printf("Solution: %.3f\n", x1);
            break;
        case 2:
            printf("Solutions: %.3f and %.3f\n", x1, x2);
            break;
        case INF_ROOTS:
            printf("The solution is any number\n");
            break;
        default:
            printf("Error in roots_amount!\n");
    }

    return 0;
}

double coeff_input(void) {
    double inputted_coefficient;
    while (scanf("%lf", &inputted_coefficient) != 1) {
        while (getchar() != '\n') continue;
        printf("This is not number! Please try again\n");
    }
    while (getchar() != '\n') continue;
    return inputted_coefficient;
}

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
        *x1ptr = (-b - sqrt(discrim)) / (2 * a);
        *x2ptr = (-b + sqrt(discrim)) / (2 * a);
        return 2;
    }
}
