#include <stdio.h>
#include <math.h>
#include <float.h>
#include <string.h>
#include "input.h"
#include "solve.h"
#include "unittests.h"

const int YES = 1;

int main(int argc, char * argv[]) { // проверка на колво флагов в начало + добавить режим чтения из файла в основном режиме
    if (argc >= 2 && strcmp(argv[1], "-t") == 0) { // слишком огромный мэйн, растащить по функциям
        printf("Square equation solver, Unit tests mode\n\n");

        run_tests();

        return 0;
    }
    else if (argc >= 2 && strcmp(argv[1], "-l") == 0) {
        printf("Square equation solver, linear equation solver mode\n\n");

        double coeffs[2] = {0, 0};

        do {
            get_coeffs(coeffs, LINEAR_COEFFS_AMOUNT);  // в функцию
            double roots[1] = {0};
            int roots_amount = solve_linear(coeffs[0], coeffs[1], &roots[0]);
            print_solutions(roots, roots_amount);
        } while (continue_program() == 1);

        printf("Goodbye!");

        return 0;

    }
    else if (argc >= 2 && strcmp(argv[1], "-s") == 0) {
        printf("Welcome to Square equation solver\n"
               "This program can solve square equations\n\n");

        double coeffs[3] = {0};
                                               // в функцию
        do {
            get_coeffs(coeffs, SQUARE_COEFFS_AMOUNT);

            double roots[2] = {0, 0};
            int roots_amount = solve(coeffs[0], coeffs[1], coeffs[2], &roots[0], &roots[1]);

            print_solutions(roots, roots_amount);
        } while (continue_program() == YES); // константа YES = 1

        printf("Goodbye!");

        return 0;
    }
    else {
        printf("Usage: %s -s for square solver mode;\n"  // -h для вывода полной инфы о квадратке
               "       %s -l for linear mode;\n"
               "       %s -t for unit tests mode;\n"
               "       %s -h to show full information",
               argv[0], argv[0], argv[0], argv[0]);
    }
}
