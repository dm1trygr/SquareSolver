#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "./headers/modes.h"
#include "./headers/input.h"
#include "./headers/output.h"
#include "./headers/solve.h"
#include "./headers/unittests.h"

void choosing_mode(int argc, char* argv[]) {
    if (argc >= 2) {
        if (strcmp(argv[1], SQUARE_MODE_FLAG) == 0) {
            run_square_mode();
        }
        else if (strcmp(argv[1], LINEAR_MODE_FLAG) == 0) {
            run_linear_mode();
        }
        else if (strcmp(argv[1], FILE_MODE_FLAG) == 0) {
            if (argc >= 4) {
                file_io_mode(argv[2], argv[3]);
            }
            else if (argc == 3) {
                file_io_mode(argv[2], DEFAULT_OUTPUT_FILENAME);
            }
            else {
                show_file_help(argv[0]);
            }
        }
        else if (strcmp(argv[1], UNIT_TESTS_FLAG) == 0) {
            run_unit_tests_mode(argc, argv);
        }
        else if (strcmp(argv[1], FULL_HELP_FLAG) == 0) {
            show_full_help(argv[0]);
        }
        else {
            show_short_help(argv[0]);
        }
    }
    else {
        show_short_help(argv[0]);
    }
}

void run_square_mode(void) {
    printf("Welcome to Square equation solver\n"
           "This program can solve square equations\n\n");

    double coeffs[3] = {0};

    do {
        get_coeffs(coeffs, SQUARE_COEFFS_NUMBER);

        double roots[2] = {0, 0};
        int roots_amount = solve_equation(coeffs[0], coeffs[1], coeffs[2], &roots[0], &roots[1]);

        print_solutions(roots, roots_amount);
    } while (ask_continue_program());

    printf("Goodbye!\n");
}

void run_linear_mode(void) {
    printf("Square equation solver, linear equation solver mode\n\n");

    double coeffs[2] = {0, 0};

    do {
        get_coeffs(coeffs, LINEAR_COEFFS_NUMBER);

        double roots[1] = {0};
        int roots_amount = solve_linear(coeffs[0], coeffs[1], &roots[0]);

        print_solutions(roots, roots_amount);
    } while (ask_continue_program());

    printf("Goodbye!\n");
}

void file_io_mode(const char* const input_file_name, const char* const output_file_name) {
    assert(input_file_name != NULL);
    assert(output_file_name != NULL);

    if (strcmp(input_file_name, output_file_name) == 0) {
        printf("Error! You're trying to open same file for reading coefficients and writing roots!\n");
        return;
    }

    FILE* input_file = fopen(input_file_name, "r");

    if (input_file == NULL) {
        printf("Error! File %s does not exist!\n", input_file_name);
        return;
    }

    FILE* output_file = fopen(output_file_name, "w");

    if (output_file == NULL) {
        printf("Error in opening %s!\n", output_file_name);
        fclose(input_file);
        return;
    }

    printf("Square equation solver, file mode\n\n");

    solve_from_file(input_file, output_file);
}

void show_file_help(const char* const program_name) {
    assert(program_name != NULL);

    printf("Usage: %s %s [input file] [output file]\n",
           program_name, FILE_MODE_FLAG);
}

void run_unit_tests_mode(int argc, char* argv[]) {
    printf("Square equation solver, Unit tests mode\n\n");

    if (argc >= 3) {
        read_tests_from_file(argv[2]);
    }
    else {
        run_tests();
    }
}

void show_full_help(const char* const program_name) {
    assert(program_name != NULL);

    printf("\n"
           "===========================SQUARE EQUATION SOLVER===========================\n"
           "This small program can solve square and linear equations, test itself and\n"
           "work with files.\n"
           "Program can work in cycle, while user wants to get solutions of square and\n"
           "linear equations\n"
           "\n"
           "USAGE: %s [option]\n"
           "\n"
           "LIST OF FLAGS:\n"
           "%s  Solves square equations. Accepts 3 coefficients. Also can solve linear\n"
           "    equation if user will enter a = 0\n"
           "%s  Solves linear equations. Accepts 2 coefficients\n"
           "%s  Opens file, reads coefficients from this file and writes coefficients\n"
           "    to another file\n"
           "    Must be used with at least 1 argument after flag (also 1 is additional):\n"
           "    %s [input file] <output file>\n"
           "    Coefficients in input file must be entered according to example below:\n"
           "    [a] [b] [c]\n"
           "%s  Begins testing of program's main solve functions. Shows status of\n"
           "    every test (OK/Not OK) and if any test(s) was failed, information\n"
           "    about this test(s)\n"
           "    You can also enter an input file with test according to example below:\n"
           "    %s <input file>\n"
           "%s  Shows full information about this program\n"
           "\n",
           program_name, SQUARE_MODE_FLAG, LINEAR_MODE_FLAG,
           FILE_MODE_FLAG, FILE_MODE_FLAG, UNIT_TESTS_FLAG,
           UNIT_TESTS_FLAG, FULL_HELP_FLAG);
}

void show_short_help(const char* const program_name) {
    assert(program_name != NULL);

    printf("Usage: %s %s for square solver mode;\n"
           "       %s %s for linear mode;\n"
           "       %s %s [input file] <output file> for file input/output mode;\n"
           "       %s %s <input file> for unit tests mode;\n"
           "       %s %s to show full information\n",
           program_name, SQUARE_MODE_FLAG,
           program_name, LINEAR_MODE_FLAG,
           program_name, FILE_MODE_FLAG,
           program_name, UNIT_TESTS_FLAG,
           program_name, FULL_HELP_FLAG);
}
