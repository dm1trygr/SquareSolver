#include <stdio.h>
#include <math.h>
#include <float.h>
#include <string.h>
#include "modes.h"

int main(int argc, char * argv[]) { // добавить режим чтени€ из файла в основном режиме
    if (argc >= 2) {
        if (strcmp(argv[1], "-t") == 0) {
            unit_tests_mode();
        }
        else if (strcmp(argv[1], "-l") == 0) {
            linear_equation_mode();
        }
        else if (strcmp(argv[1], "-s") == 0) {
            square_equation_mode();
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

