#include <stdio.h>
#include <math.h>
#include <float.h>
#include <string.h>
#include "modes.h"

int main(int argc, char * argv[]) { // добавить режим чтени€ из файла в основном режиме
    if (argc >= 2) {
        if (strcmp(argv[1], SQUARE_MODE_FLAG) == 0) {
            square_equation_mode();
        }
        else if (strcmp(argv[1], LINEAR_MODE_FLAG) == 0) {
            linear_equation_mode();
        }
        else if (strcmp(argv[1], FILE_MODE_FLAG) == 0) {
            file_mode();
        }
        else if (strcmp(argv[1], UNIT_TESTS_MODE) == 0) {
            unit_tests_mode();
        }
        else if (strcmp(argv[1], FULL_HELP_MODE) == 0) {
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

