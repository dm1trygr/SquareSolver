#ifndef SOLVE_HEADER
#define SOLVE_HEADER

#include "roots_amount.h"

struct Coeffs {
    double value[3];
    unsigned int amount;
};

struct Roots {
    double value[2];
    unsigned int amount;
};

//-----------------------------------------------------
//!Checks if double-type numbers is equal
//!
//!@param [in]  num1   Double-type number 1
//!@param [in]  num2   Double-type number 2
//!
//!@return Returns 1 if numbers are equal, otherwise 0
//-----------------------------------------------------

bool are_doubles_equal(const double num1, const double num2);

//-----------------------------------------------------
//!Checks if double-type number is equal to 0
//!
//!@param [in]  number Double-type number
//!
//!@return Returns 1 if number is equal to 0, otherwise 0
//-----------------------------------------------------

static bool is_equal_to_zero(const double number);

//-----------------------------------------------------
//!If number is close to 0, returns 0, otherwise number
//!
//!@param [in]  number Double-type value
//!
//!@return 0 if number is close to zero, otherwise number
//!
//!@see is_doubles_equal()
//-----------------------------------------------------

static double round_to_zero(const double number);

//-----------------------------------------------------
//!Assign the first variable to the value of the second,
//!and the second to the value of the first
//!
//!@param [out] num1_ptr Pointer to 1st number
//!@param [out] num2_ptr Pointer to 2nd number
//-----------------------------------------------------

static void swap_numbers(double* const num1_ptr, double* const num2_ptr);

//-----------------------------------------------------
//!Solves square equation
//!
//!@param [in]  a      a-parameter
//!@param [in]  b      b-parameter
//!@param [in]  c      c-parameter
//!@param [out] x1ptr  Pointer to 1st root
//!@param [out] x2ptr  Pointer to 2nd root
//!
//!@return Amount of roots or INF_ROOTS if amount of
//!        solutions is infinite
//!
//!@see linear()
//-----------------------------------------------------

RootsAmount solve_equation(const double a, const double b, const double c,
                           double* const x1ptr, double* const x2ptr);

//-----------------------------------------------------
//!Solves linear equation
//!
//!@param [in]  b      b-parameter
//!@param [in]  c      c-parameter
//!@param [out] x1ptr  Pointer to root
//!
//!@return Amount of roots or INF_ROOTS if amount of
//!        solutions is infinite
//-----------------------------------------------------

RootsAmount solve_linear(const double b, const double c, double* const x1ptr);

#endif
