#include <stdio.h>
#include "modes.h"
#include "input.h"
#include "solve.h"
#include "unittests.h"
#include "fileio.h"

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

    printf("Goodbye!\n");
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

    printf("Goodbye!\n");
}

void file_mode(void) {  // растащить по функциям
    printf("Square equation solver, file mode\n\n");

    char input_filename[MAX_FILENAME_LEN] = "", output_filename[MAX_FILENAME_LEN] = "";

    printf("Enter input file:\n");
    scanf("%s", input_filename);
    FILE * input_fp;
    while ((input_fp = fopen(input_filename, "r")) == NULL) {
        printf("File %s does not exists! Please try again:\n", input_filename);
        scanf("%s", input_filename);
    }
    //get_file_pointer(input_fp, "r");

    printf("Enter output file:\n");
    scanf("%s", output_filename);
    FILE * output_fp;
    while ((output_fp = fopen(output_filename, "a")) == NULL) {
        printf("Can't open file! Please try again:\n");
        scanf("%s", input_filename);
    }
    //get_file_pointer(output_fp, "a")

    double coeffs[3] = {0}, roots[2] = {0};
    int equation_number = 1;

    fprintf(output_fp, "Solutions:\n");

    while (fscanf(input_fp, "%lf %lf %lf", &coeffs[0], &coeffs[1], &coeffs[2]) == 3) {
        int roots_amount = solve(coeffs[0], coeffs[1], coeffs[2], &roots[0], &roots[1]);
        fprintf(output_fp, "EQUATION %d: ", equation_number++);
        fprint_solutions(output_fp, roots, roots_amount);
    }

    fputc('\n', output_fp);
}

void unit_tests_mode(void) {
    printf("Square equation solver, Unit tests mode\n\n");

    run_tests();
}

void full_help(const char * const program_name) {
    printf("\n"
           "==========================SQUARE EQUATION SOLVER==========================\n"
           "This small program can solve square and linear equations, test itself and\n"
           "work with files.\n"
           "Program can work in cycle, while user wants to get solutions of square and\n"
           "linear equations\n"
           "\n"
           "USAGE: %s -flag\n"
           "\n"
           "LIST OF FLAGS:\n"
           "%s  Solves square equations. Accepts 3 coefficients. Works while user\n"
           "    wants to solve square equations. Also can solve linear equation if\n"
           "    user will enter a = 0.\n"
           "%s  Solves linear equations. Accepts 2 coefficients. Works while user\n"
           "    wants to solve linear equations.\n"
           "%s  Opens file, reads coefficients from this file and writes coefficients\n"
           "    to another file\n"
           "%s  Begins testing of program's main solve functions. Shows status of\n"
           "    every test (OK/Not OK) and if any test(s) was failed, information\n"
           "    about this test(s)\n"
           "%s  Shows full information about this program\n"
           "\n",
           program_name, SQUARE_MODE_FLAG, LINEAR_MODE_FLAG,
           FILE_MODE_FLAG, UNIT_TESTS_MODE, FULL_HELP_MODE);
}

void short_help(const char * const program_name) {
    printf("Usage: %s %s for square solver mode;\n"
           "       %s %s for linear mode;\n"
           "       %s %s for file input/output mode;\n"
           "       %s %s for unit tests mode;\n"
           "       %s %s to show full information\n",
           program_name, SQUARE_MODE_FLAG,
           program_name, LINEAR_MODE_FLAG,
           program_name, FILE_MODE_FLAG,
           program_name, UNIT_TESTS_MODE,
           program_name, FULL_HELP_MODE);
}

