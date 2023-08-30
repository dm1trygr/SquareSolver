#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "./headers/modes.h"
#include "./headers/input.h"
#include "./headers/output.h"
#include "./headers/solve.h"
#include "./headers/unittests.h"

SolverModes choosing_mode(const unsigned int argc, const char* argv[]) {
    assert(argv != NULL);

    if (argc >= 2) {
        if (strcmp(argv[1], SQUARE_MODE_FLAG) == 0) {
            return SQUARE;
        }
        else if (strcmp(argv[1], LINEAR_MODE_FLAG) == 0) {
            return LINEAR;
        }
        else if (strcmp(argv[1], FILE_MODE_FLAG) == 0) {
            if (argc >= 4) {
                return FILE_IO;
            }
            else if (argc == 3) {
                return FILE_I;
            }
            else {
                return FILE_HELP;
            }
        }
        else if (strcmp(argv[1], UNIT_TESTS_FLAG) == 0) {
            return UNIT_TESTS;
        }
        else if (strcmp(argv[1], FULL_HELP_FLAG) == 0) {
            return FULL_HELP;
        }
        else {
            return SHORT_HELP;
        }
    }
    else {
        return SHORT_HELP;
    }
}

void run_square_mode(void) {
    Coeffs coefficients = {{0, 0, 0}, SQUARE_COEFFS_NUMBER};

    do {
        get_coeffs(&coefficients);

        Roots roots = {{0, 0}, 0};
        roots.amount = solve_equation(coefficients.value[0],
                                      coefficients.value[1],
                                      coefficients.value[2],
                                      &roots.value[0],
                                      &roots.value[1]);

        print_solutions(&roots);
    } while (ask_continue_program());
}

void run_linear_mode(void) {
    Coeffs coefficients = {{0, 0, 0}, LINEAR_COEFFS_NUMBER};

    do {
        get_coeffs(&coefficients);

        Roots roots = {{0, 0}, 0};
        roots.amount = solve_linear(coefficients.value[0],
                                    coefficients.value[1],
                                    &roots.value[0]);

        print_solutions(&roots);
    } while (ask_continue_program());
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

    FILE* output_file = stdout;

    if (output_file_name[0] != '\0') {
        output_file = fopen(output_file_name, "w");

        if (output_file == NULL) {
            printf("Error in opening %s!\n", output_file_name);
            fclose(input_file);
            return;
        }
    }

    solve_from_file(input_file, output_file);

    fclose(input_file);

    output_file != stdout ? fclose(output_file) : 0;
}

void show_file_help(const char* const program_name) {
    assert(program_name != NULL);

    printf("Usage: %s %s [input file] [output file]\n",
           program_name, FILE_MODE_FLAG);
}

void run_unit_tests_mode(const unsigned int argc, const char* argv[]) {
    assert(argv != NULL);

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
           "    If name of output file wasn't entered, program will print solutions to\n"
           "    terminal\n"
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
