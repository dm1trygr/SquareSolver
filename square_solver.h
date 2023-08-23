static const int INF_ROOTS = 3;

void get_3_coeffs(double * const a_ptr, double * const b_ptr, double * const c_ptr);

double one_coeff_input(void);

void clear_input_buffer(void);

int is_doubles_equal(const double num1, const double num2);

int solve(const double a, const double b, const double c, double * const x1ptr, double * const x2ptr);

int linear(const double b, const double c, double * const x1ptr);

int square(const double a, const double b, const double c, double * const x1ptr, double * const x2ptr);

void print_solutions(const int roots_amount, const double x1, const double x2);

double round_to_zero(const double number);

int runtests(void);

int onetest(const double a, const double b, const double c, const double x1ref, const double x2ref, const int amtref);
