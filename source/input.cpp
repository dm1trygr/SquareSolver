#include <stdio.h>
#include <assert.h>
#include "./headers/input.h"

void get_coeffs(double coeffs[], const unsigned int amount) {
    assert(coeffs != NULL);

    for (unsigned int index = 0; index < amount; index++) {
        printf("Enter coefficient %c:\n", 'a' + index);

        coeffs[index] = input_one_coeff();
    }
}

double input_one_coeff(void) {
    double input_coefficient = 0;

    while (1) {
        if (scanf("%lg", &input_coefficient) == 1 && getchar() == '\n') {
            return input_coefficient;
        }
        else {
            clear_input_buffer();
            printf("This is not a number! Please try again\n");
        }
    }
}

int ask_continue_program(void) {
    printf("Do you want to continue?\n"
           "%d - no\n"
           "%d - yes\n",
           BREAK_FLAG, CONTINUE_FLAG);

    int flag = 0;

    while (1) {
        if (scanf("%d", &flag) == 1  && getchar() == '\n') {
            if (flag == BREAK_FLAG || flag == CONTINUE_FLAG) {
                return flag;
            }
            else {
                printf("This is not %d or %d! Please try again\n", BREAK_FLAG, CONTINUE_FLAG);
            }
        }
        else {
            printf("This is not a number! Please try again\n");
            clear_input_buffer();
        }
    }
}

void clear_input_buffer(void) {
    while (getchar() != '\n') {}
}
