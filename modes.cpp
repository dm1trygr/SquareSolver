#include <stdio.h>
#include "modes.h"
#include "input.h"
#include "solve.h"
#include "unittests.h"

void unit_tests_mode(void) {
    printf("Square equation solver, Unit tests mode\n\n");

    run_tests();
}

void linear_equation_mode(void) {
    printf("Square equation solver, linear equation solver mode\n\n");

    double coeffs[2] = {0, 0};

    do {
        get_coeffs(coeffs, LINEAR_COEFFS_AMOUNT);  // в функцию
        double roots[1] = {0};
        int roots_amount = solve_linear(coeffs[0], coeffs[1], &roots[0]);
        print_solutions(roots, roots_amount);
    } while (continue_program() == 1);

    printf("Goodbye!");
}

void square_equation_mode(void) {
    printf("Welcome to Square equation solver\n"
           "This program can solve square equations\n\n");

    double coeffs[3] = {0};
                                               // в функцию
    do {
        get_coeffs(coeffs, SQUARE_COEFFS_AMOUNT);

        double roots[2] = {0, 0};
        int roots_amount = solve(coeffs[0], coeffs[1], coeffs[2], &roots[0], &roots[1]);

        print_solutions(roots, roots_amount);
    } while (continue_program() == YES);

    printf("Goodbye!");
}

void short_help(const char * const program_name) {
    printf("Usage: %s -s for square solver mode;\n"  // -h для вывода полной инфы о квадратке
           "       %s -l for linear mode;\n"
           "       %s -t for unit tests mode;\n"
           "       %s -h to show full information",
           program_name, program_name, program_name, program_name);
}

