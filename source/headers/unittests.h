#ifndef UNITTESTS_HEADER
#define UNITTESTS_HEADER

static const int MAX_NAME_LEN = 50;  //!<Maximum test name length

//!Structure with data about tests: coefficients of equation,
//!right roots and their amount

struct TestReference {
    double a;  //!<a-coefficient
    double b;  //!<b-coefficient
    double c;  //!<c-coefficient
    double x1ref;  //!<Reference (right) root #1
    double x2ref;  //!<Reference (right) root #2
    int amount_ref;  //!<Reference (right) amount of roots
    char test_name[MAX_NAME_LEN];  //!<Name of test
};

//-----------------------------------------------------
//!Does unit tests of solve()
//!
//!@return Amount of successful tests
//!
//!@see solve_equation(), run_one_test(), check_test_output()
//-----------------------------------------------------

int run_tests(void);

//-----------------------------------------------------
//!Gets data about tests from file and does this tests
//!of solve()
//!
//!@param [in]  input_filename Pointer to input file
//!
//!@return Amount of successful tests
//!
//!@see run_one_test()
//-----------------------------------------------------

int read_tests_from_file(const char* const input_filename);

bool get_root_amount_ref(const char * const raw_amount, int* const amount);

//-----------------------------------------------------
//!Does 1 unit test of solve()
//!
//!@param [in]  current_test Structure with coefficients
//!                          and reference values
//!
//!@return 1 if received roots and amount is equal to
//!        reference, otherwise 0
//!
//!@see solve_equation(), check_test_output()
//-----------------------------------------------------

static int run_one_test(const TestReference* const current_test);

//-----------------------------------------------------
//!Compare test output with reference values
//!
//!@param [in]  x1           First root from
//!                          solve_equation()
//!@param [in]  x2           Second root from
//!                          solve_equation()
//!@param [in]  amount       Amount of roots from
//!                          solve_equation()
//!@param [in]  current_test Pointer to structure with
//!                          reference values
//!
//!@return 1 if output from solve() equal to reference
//!        values, otherwise 0
//-----------------------------------------------------

static bool check_test_output(const double x1, const double x2, const int amount,
                              const TestReference* const current_test);

#endif
