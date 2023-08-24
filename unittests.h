const int N_TESTS = 7;
const int MAX_NAME_LEN = 50;

struct test_reference {
    const double a, b, c;
    const double x1ref, x2ref;
    const int amount_ref;
    const char test_name[MAX_NAME_LEN];
};

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
//!@param [in]  current_test Structure with coefficients
//!                          and reference values
//!
//!@return 1 if received roots and amount is equal to
//!        reference, otherwise 0
//!
//!@see solve()
//-----------------------------------------------------

int do_one_test(const test_reference * const current_test);

