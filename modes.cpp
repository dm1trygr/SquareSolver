#include <stdio.h>
#include "modes.h"
#include "input.h"
#include "solve.h"
#include "unittests.h"

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

void file_mode(void) {

}

void unit_tests_mode(void) {
    printf("Square equation solver, Unit tests mode\n\n");

    run_tests();
}

void full_help(const char * const program_name) {

}

void short_help(const char * const program_name) {
    printf("Usage: %s %s for square solver mode;\n"  // -h для вывода полной инфы о квадратке
           "       %s %s for linear mode;\n"
           "       %s %s for file input/output mode;\n"
           "       %s %s for unit tests mode;\n"
           "       %s %s to show full information",
           program_name, SQUARE_MODE_FLAG,
           program_name, LINEAR_MODE_FLAG,
           program_name, FILE_MODE_FLAG,
           program_name, UNIT_TESTS_MODE,
           program_name, FULL_HELP_MODE);
}

