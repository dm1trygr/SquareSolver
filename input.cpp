#include <stdio.h>
#include <assert.h>
#include "input.h"

void get_3_coeffs(double * const a_ptr, double * const b_ptr, double * const c_ptr) { // переписать
    assert(a_ptr != NULL);
    assert(b_ptr != NULL);
    assert(c_ptr != NULL);

    printf("Enter first number (a):\n");
    *a_ptr = one_coeff_input();

    printf("Now enter second number (b):\n");
    *b_ptr = one_coeff_input();

    printf("And finally, enter third number (c):\n");
    *c_ptr = one_coeff_input();

}

double one_coeff_input(void) {
    double input_coefficient = 0;

    while (scanf("%lf", &input_coefficient) != 1) {
        clear_input_buffer();
        printf("This is not a number! Please try again\n");
    }
    clear_input_buffer();

    return input_coefficient;
}

void clear_input_buffer(void) {
    while (getchar() != '\n') {};
}
