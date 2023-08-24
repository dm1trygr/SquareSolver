static const int INF_ROOTS = 888;

//-----------------------------------------------------
//!Checks if double-type numbers is equal
//!
//!@param [in]  number Double-type number 1
//!@param [in]  number Double-type number 2
//!
//!@return Returns 1 if numbers are equal, otherwise 0
//-----------------------------------------------------

int is_doubles_equal(const double num1, const double num2);

//-----------------------------------------------------
//!If number is close to 0, returns 0, otherwise number
//!
//!@param [in]  number Double-type value
//!
//!@return 0 if number is close to zero, otherwise number
//!
//!@see is_doubles_equal()
//-----------------------------------------------------

double round_to_zero(const double number);

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
//!@see linear(), square()
//-----------------------------------------------------

int solve(const double a, const double b, const double c, double * const x1ptr, double * const x2ptr);

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

int solve_linear(const double b, const double c, double * const x1ptr);

//-----------------------------------------------------
//!Solves square equation with a != 0
//!
//!@param [in]  a      a-parameter
//!@param [in]  b      b-parameter
//!@param [in]  c      c-parameter
//!@param [out] x1ptr  Pointer to 1st root
//!@param [out] x2ptr  Pointer to 2nd root
//!
//!@return Amount of roots
//-----------------------------------------------------

int solve_square(const double a, const double b, const double c, double * const x1ptr, double * const x2ptr);

//-----------------------------------------------------
//!Prints solutions of equation
//!
//!@param [in]  roots[] Array of solutions
//!@param [in]  amount  Amount of solutions
//-----------------------------------------------------

void print_solutions(const double roots[], const int amount);