#ifndef INPUT_HEADER
#define INPUT_HEADER

#include "solve.h"

//!Amount of coefficients in linear equation
const unsigned int LINEAR_COEFFS_NUMBER = 2;
//!Amount of coefficients in square equation
const unsigned int SQUARE_COEFFS_NUMBER = 3;

//!Flag for ask_continue_program() at the return of which the program should be terminated
const unsigned int BREAK_FLAG = 0;
//!Flag for ask_continue_program() at the return of which the program should continue working
const unsigned int CONTINUE_FLAG = 1;

//-----------------------------------------------------
//!Gets coefficients from standard input
//!
//!@param [out] coeffs[] Structure with coefficients and
//!                      their amount
//!
//!@see input_one_coeff(), check_input_buffer()
//-----------------------------------------------------

void get_coeffs(Coeffs* const coefficients);

//-----------------------------------------------------
//!Gets one number from standard input
//!
//!@return Double-type value
//!
//!@note If you try to enter a non-numeric value, it
//!      displays a corresponding message and allows
//!      you to enter another value
//!
//!@see clear_input_buffer()
//-----------------------------------------------------

static double input_one_coeff(void);

//-----------------------------------------------------
//!Asks a user if he wish stop or continue program
//!
//!@return CONTINUE_FLAG if user wants to continue,
//!        otherwise BREAK_FLAG
//!
//!@see clear_input_buffer()
//-----------------------------------------------------

int ask_continue_program(void);

//-----------------------------------------------------
//!Clears input buffer
//-----------------------------------------------------

static void clear_input_buffer(void);

//-----------------------------------------------------
//!Checks if there are non-space symbols after number.
//!Also clears input buffer from non-space symbols
//!
//!@return 1 if input string is clear (don't contain
//!non-space characters after number), otherwise 0
//-----------------------------------------------------

static bool check_input_buffer(void);

#endif
