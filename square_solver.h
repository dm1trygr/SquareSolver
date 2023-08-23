static const int INF_ROOTS = 3;

//-----------------------------------------------------
//!Gets three coefficients from input
//!
//!@param [out] a_ptr  Pointer to a-coefficient
//!@param [out] b_ptr  Pointer to b-coefficient
//!@param [out] c_ptr  Pointer to c-coefficient
//!
//!@see one_coeff_input()
//-----------------------------------------------------

void get_3_coeffs(double * const a_ptr, double * const b_ptr, double * const c_ptr);

//-----------------------------------------------------
//!Gets one number from input
//!
//!@return Double-type value
//!
//!@note If you try to enter a non-numeric value, it
//!      displays a corresponding message and allows
//!      you to enter another value
//-----------------------------------------------------

double one_coeff_input(void);

//-----------------------------------------------------
//!Clears input buffer
//!
//!@see clear_input_buffer()
//-----------------------------------------------------

void clear_input_buffer(void);

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

int linear(const double b, const double c, double * const x1ptr);

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

int square(const double a, const double b, const double c, double * const x1ptr, double * const x2ptr);

//-----------------------------------------------------
//!Prints solutions of equation
//!
//!@param [in]  roots_amount Amount of roots
//!@param [in]  x1           First root
//!@param [in]  x2           Second root
//-----------------------------------------------------

void print_solutions(const int roots_amount, const double x1, const double x2);

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
//!Does unit tests of solve()
//!
//!@return Amount of successful tests
//!
//!@see solve(), onetest()
//-----------------------------------------------------

int runtests(void);

//-----------------------------------------------------
//!Does 1 unit test of solve()
//!
//!@param [in]  a      a-coefficient
//!@param [in]  b      b-coefficient
//!@param [in]  c      c-coefficient
//!@param [in]  x1ref  Reference root 1
//!@param [in]  x2ref  Reference root 2
//!@param [in]  amtref Reference amount of roots
//!
//!@return 1 if received roots and amount is equal to
//!        reference, otherwise 0
//!
//!@see solve()
//-----------------------------------------------------

int onetest(const double a, const double b, const double c, const double x1ref, const double x2ref, const int amtref);
