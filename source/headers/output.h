#ifndef OUTPUT_HEADER
#define OUTPUT_HEADER

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

void fprint_solutions(FILE* file_pointer, const double roots[], const unsigned int amount);

void solve_from_file(FILE* input_file, FILE* output_file);

#endif
