#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "./headers/output.h"
#include "./headers/solve.h"
#include "./headers/roots_amount.h"

void print_solutions(const Roots* const roots) {
    assert(roots != NULL);

    fprint_solutions(stdout, roots);
}

void fprint_solutions(FILE* const file_pointer, const Roots * const roots) {
    assert(file_pointer != NULL);
    assert(roots != NULL);

    switch(roots->amount) {
        case NO_ROOTS:
            fprintf(file_pointer, "No solutions\n");
            break;
        case INF_ROOTS:
            fprintf(file_pointer, "Solution is any number\n");
            break;
        case ONE_ROOT:
            fprintf(file_pointer, "(1 solution) %.3f\n", roots->value[0]);
            break;
        default:
            fprintf(file_pointer, "(%d solutions) ", roots->amount);
            for (unsigned int index = 0; index < roots->amount; index++) {
                fprintf(file_pointer, "%.3f ", roots->value[index]);
            }
            fputc('\n', file_pointer);
    }
}

void solve_from_file(FILE* const input_file, FILE* const output_file) {
    assert(input_file != NULL);
    assert(output_file != NULL);

    Coeffs coefficients = {{0, 0, 0}, 3};
    Roots roots = {{0, 0}, 0};

    int equation_number = 1;
    int success_solved = 0;

    fprintf(output_file, "Solutions:\n");

    while (1) {
        if (fscanf(input_file, "%lg %lg %lg", &coefficients.value[0], &coefficients.value[1],
            &coefficients.value[2]) == 3) {
            roots.amount = solve_equation(coefficients.value[0],
                                              coefficients.value[1],
                                              coefficients.value[2],
                                              &roots.value[0],
                                              &roots.value[1]);

            fprintf(output_file, "EQUATION %d: ", equation_number++);
            fprint_solutions(output_file, &roots);

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

                printf("Solved %d out of %d equation(s)! ",
                       success_solved, equation_number - 1);

                return;
            }
        }
    }
}
