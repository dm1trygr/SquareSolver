#include <stdio.h>
#include <assert.h>
#include "fileio.h"

/*void get_file_pointer() {
    scanf("%s", input_filename);
    FILE * input_fp;
    while ((input_fp = fopen(input_filename, "r")) == NULL) {
        printf("File %s does not exists! Please try again:\n", input_filename);
        scanf("%s", input_filename);
    }
}*/

void fprint_solutions(FILE * file_pointer, const double roots[], const unsigned int amount) {
    if (amount == 0) {
        fprintf(file_pointer, "No solutions\n");
    }
    else if (amount == 888) {
        fprintf(file_pointer, "Solution is any number\n");
    }
    else {
        fprintf(file_pointer, "(%d solutions) ", amount);
        for (int index = 0; index < amount; index++) {
            fprintf(file_pointer, "%.3f ", roots[index]);
        }
        fputc('\n', file_pointer);
    }
}
