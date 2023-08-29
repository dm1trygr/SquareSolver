#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "./source/headers/output.h"
#include "./source/headers/roots_amount.h"

void print_solutions(const double roots[], const unsigned int amount) {
    assert(roots != NULL);
    assert(isfinite(amount));

    fprint_solutions(stdout, roots, amount);
}

void fprint_solutions(FILE * file_pointer, const double roots[], const unsigned int amount) {
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
