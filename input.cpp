#include <stdio.h>
#include <assert.h>
#include "input.h"

void get_coeffs(double coeffs[], const int amount) {
    assert(coeffs != NULL);
    assert(amount >= 0);

    for (int i = 0; i < amount; i++) {
        printf("Enter coefficient %d:\n", i + 1);

        coeffs[i] = one_coeff_input();
    }
}

double one_coeff_input(void) {
    double input_coefficient = 0;

    while (scanf("%lg", &input_coefficient) != 1) {
        clear_input_buffer();
        printf("This is not a number! Please try again\n");
    }
    clear_input_buffer();

    return input_coefficient;
}


int continue_program(void) {
    printf("Do you want to continue?\n"
           "0 - no\n"
           "1 - yes\n");

    int flag = 0;

    while (scanf("%d", &flag) != 1 && flag != 0 && flag != 1) {
        clear_input_buffer();
        printf("This is not a 0 or 1! Please try again\n");
    }
    clear_input_buffer();

    return flag;
}

void clear_input_buffer(void) {
    while (getchar() != '\n') {};
}
