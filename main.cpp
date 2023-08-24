#include <stdio.h>
#include <math.h>
#include <float.h>
#include <string.h>
#include "input.h"
#include "solve.h"
#include "unittests.h"

// exe лучше на гитхабе не хранить
// gitignore
// readme
int main(int argc, char * argv[]) {
    if (argc >= 2 && strcmp(argv[1], "-t") == 0) {
        printf("Square equation solver, Unit tests mode\n\n");

        run_tests();

        return 0;
    }
    /*else if (argc >= 2 && strcmp(argv[1], "-l") == 0) {

    }*/
    else {  // в цикл + можно добавить режим где решаются толькои лтинейные
        printf("Welcome to Square equation solver\n"
               "This program can solve square equations\n\n");

        double a = 0, b = 0, c = 0;

        get_3_coeffs(&a, &b, &c);

        double x1 = 0, x2 = 0;
        int roots_amount = solve(a, b, c, &x1, &x2);

        print_solutions(roots_amount, x1, x2);

        printf("Press any key to exit from program\n");
        getchar();

        return 0;
    }
}
