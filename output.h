#ifndef output_header
#define output_header

//-----------------------------------------------------
//!Prints solutions of equation
//!
//!@param [in]  roots[] Array of solutions
//!@param [in]  amount  Amount of solutions
//-----------------------------------------------------

void print_solutions(const double roots[], const unsigned int amount);

//-----------------------------------------------------
//!Prints solutions of equation with coefficients from file
//!
//!@param [in]  file_pointer Pointer to the file
//!@param [in]  roots[]      Array of solutions
//!@param [in]  amount       Amount of solutions
//-----------------------------------------------------

void fprint_solutions(FILE * file_pointer, const double roots[], const unsigned int amount);

#endif
