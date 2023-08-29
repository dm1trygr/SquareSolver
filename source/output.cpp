#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "./headers/output.h"
#include "./headers/solve.h"  // for solve_from_file() function
#include "./headers/roots_amount.h"

void print_solutions(const double roots[], const unsigned int amount) {
    assert(roots != NULL);
    assert(isfinite(amount));

    fprint_solutions(stdout, roots, amount);
}

void fprint_solutions(FILE* file_pointer, const double roots[], const unsigned int amount) {
    assert(file_pointer != NULL);
    assert(roots != NULL);
    assert(isfinite(amount));

    switch(amount) {
        case NO_ROOTS:
            fprintf(file_pointer, "No solutions\n");
            break;
        case INF_ROOTS:
            fprintf(file_pointer, "Solution is any number\n");
            break;
        case ONE_ROOT:
            fprintf(file_pointer, "(1 solution) %.3f\n", roots[0]);
            break;
        default:
            fprintf(file_pointer, "(%d solutions) ", amount);
            for (unsigned int index = 0; index < amount; index++) {
                fprintf(file_pointer, "%.3f ", roots[index]);
            }
            fputc('\n', file_pointer);
    }
}

void solve_from_file(FILE* input_file, FILE* output_file) {
    assert(input_file != NULL);
    assert(output_file != NULL);

    double coeffs[3] = {0};
    double roots[2] = {0};

    int equation_number = 1;
    int success_solved = 0;

    fprintf(output_file, "Solutions:\n");

    while (1) {
        if (fscanf(input_file, "%lg %lg %lg", &coeffs[0], &coeffs[1], &coeffs[2]) == 3) {
            int roots_amount = solve_equation(coeffs[0], coeffs[1], coeffs[2], &roots[0], &roots[1]);

            fprintf(output_file, "EQUATION %d: ", equation_number++);
            fprint_solutions(output_file, roots, roots_amount);

            success_solved++;
        }
        else {
            int ch = '\0';
            while ((ch = fgetc(input_file)) != '\n' && ch != EOF) {};
            if (ch != EOF) {
                fprintf(output_file, "EQUATION %d: Coefficient reading error!\n", equation_number++);
            }
            else {
                fputc('\n', output_file);

                printf("Solved %d out of %d equation(s)! Goodbye!\n",
                       success_solved, equation_number - 1);

                fclose(input_file);
                fclose(output_file);
                return;
            }
        }
    }
}
