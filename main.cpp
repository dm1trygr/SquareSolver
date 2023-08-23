#include <stdio.h>
#include <math.h>
#include <float.h>
#include "square_solver.h"

int main(void) {
    printf("Welcome to Square equation solver\n"
           "This program can solve square equations\n\n");

    double a = 0, b = 0, c = 0;

    get_3_coeffs(&a, &b, &c);

    double x1 = 0, x2 = 0;
    int roots_amount = solve(a, b, c, &x1, &x2);

    print_solutions(roots_amount, x1, x2);

    printf("Press any key to exit from program\n");
    getchar();

    return 0;
}
