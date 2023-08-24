//-----------------------------------------------------
//!Does unit tests of solve()
//!
//!@return Amount of successful tests
//!
//!@see solve(), do_one_test()
//-----------------------------------------------------

int run_tests(void);

//-----------------------------------------------------
//!Does 1 unit test of solve()
//!
//!@param [in]  a          a-coefficient
//!@param [in]  b          b-coefficient
//!@param [in]  c          c-coefficient
//!@param [in]  x1ref      Reference root 1
//!@param [in]  x2ref      Reference root 2
//!@param [in]  amount_ref Reference amount of roots
//!
//!@return 1 if received roots and amount is equal to
//!        reference, otherwise 0
//!
//!@see solve()
//-----------------------------------------------------

int do_one_test(const double a, const double b, const double c, const double x1ref, const double x2ref, const int amtref);

