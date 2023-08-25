#include <stdio.h>
#include <math.h>
#include <float.h>
#include <string.h>
#include "modes.h"

int main(int argc, char * argv[]) {
    if (argc >= 2) {
        if (strcmp(argv[1], SQUARE_MODE_FLAG) == 0) {
            square_equation_mode();
        }
        else if (strcmp(argv[1], LINEAR_MODE_FLAG) == 0) {
            linear_equation_mode();
        }
        else if (strcmp(argv[1], FILE_MODE_FLAG) == 0 && argc >= 4) {
            file_mode(argv[2], argv[3]);
        }
        else if (strcmp(argv[1], FILE_MODE_FLAG) == 0) {
            short_file_help(argv[0]);
        }
        else if (strcmp(argv[1], UNIT_TESTS_FLAG) == 0) {
            unit_tests_mode();
        }
        else if (strcmp(argv[1], FULL_HELP_FLAG) == 0) {
            full_help(argv[0]);
        }
        else {
            short_help(argv[0]);
        }
    }
    else {
        short_help(argv[0]);
    }

    return 0;
}

