#ifndef INPUT_HEADER
#define INPUT_HEADER

const unsigned int LINEAR_COEFFS_NUMBER = 2;
const unsigned int SQUARE_COEFFS_NUMBER = 3;

const unsigned int BREAK_FLAG = 0;
const unsigned int CONTINUE_FLAG = 1;

//-----------------------------------------------------
//!Gets coefficients from standard input
//!
//!@param [out] coeffs[] Array for coefficients
//!@param [in]  amount   Amount of coefficients
//!
//!@see input_one_coeff()
//-----------------------------------------------------

void get_coeffs(double coeffs[], const unsigned int amount);

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

double input_one_coeff(void);

//-----------------------------------------------------
//!Asks a user if he wish stop or continue program
//!
//!@return 1 if user wants to continue, otherwise 0
//!
//!@see clear_input_buffer()
//-----------------------------------------------------

int ask_continue_program(void);

//-----------------------------------------------------
//!Clears input buffer
//-----------------------------------------------------

void clear_input_buffer(void);

#endif
