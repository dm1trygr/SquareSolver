#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include "./headers/input.h"
#include "./headers/solve.h"

void get_coeffs(Coeffs* const coefficients) {
    assert(coefficients != NULL);

    for (unsigned int index = 0; index < coefficients->amount; index++) {
        printf("Enter coefficient %c:\n", 'a' + index);

        coefficients->value[index] = input_one_coeff();
    }
}

static double input_one_coeff(void) {
    double input_coefficient = 0;

    while (1) {
        if (scanf("%lg", &input_coefficient) == 1 && check_input_buffer()) {
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

static void clear_input_buffer(void) {
    while (getchar() != '\n') {}
}

static bool check_input_buffer(void) {
    char ch = '\0';
    while ((ch = getchar()) != '\n') {
        if (!isblank(ch)) {return 0;};
    }
    return 1;
}
