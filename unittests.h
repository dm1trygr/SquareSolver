const int N_TESTS = 7;  //!<Total amount of unit tests in unittest.cpp
const int MAX_NAME_LEN = 50;  //!<Maximum test name length

//!Structure with data about tests: coefficients of equation,
//!right roots and their amount

struct test_reference {
    const double a;  //!<a-coefficient
    const double b;  //!<b-coefficient
    const double c;  //!<c-coefficient
    const double x1ref;  //!<Reference (right) root #1
    const double x2ref;  //!<Reference (right) root #2
    const int amount_ref;  //!<Reference (right) amount of roots
    const char test_name[MAX_NAME_LEN];  //!<Name of test
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

