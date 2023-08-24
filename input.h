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
