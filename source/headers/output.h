#ifndef OUTPUT_HEADER
#define OUTPUT_HEADER

#include "solve.h"

//-----------------------------------------------------
//!Prints solutions of equation
//!
//!@param [in]  roots[] Array of solutions
//!@param [in]  amount  Amount of solutions
//!
//!@see fprint_solutions()
//-----------------------------------------------------

void print_solutions(const Roots * roots);

//-----------------------------------------------------
//!Prints solutions of equation with coefficients from file
//!
//!@param [in]  file_pointer Pointer to the file
//!@param [in]  roots[]      Array of solutions
//!@param [in]  amount       Amount of solutions
//-----------------------------------------------------

void fprint_solutions(FILE* const file_pointer, const Roots * roots);

//-----------------------------------------------------
//!Reads coefficients from file and prints solution to
//!other file
//!
//!@param [in]  input_file  Pointer to input file
//!@param [out] output_file Pointer to output file
//!
//!@note If function will read string with invalid value,
//!      it will
//!      skip a string with this value
//!
//!@see fprint_solutions(), solve_equation()
//-----------------------------------------------------

void solve_from_file(FILE* const input_file, FILE* const output_file);

#endif
