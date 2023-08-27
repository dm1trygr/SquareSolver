#ifndef unittests_header
#define unittests_header

const int MAX_NAME_LEN = 50;  //!<Maximum test name length

//!Structure with data about tests: coefficients of equation,
//!right roots and their amount

struct TestReference {
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
//!@see solve(), run_one_test()
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

int run_one_test(const TestReference * const current_test);

bool check_test_output(double x1, double x1ref, double x2, double x2ref, int amount, int amount_ref);

#endif
