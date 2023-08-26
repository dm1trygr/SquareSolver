const int YES = 1;

const char SQUARE_MODE_FLAG[] = "-s";
const char LINEAR_MODE_FLAG[] = "-l";
const char FILE_MODE_FLAG[] = "-f";
const char UNIT_TESTS_FLAG[] = "-t";
const char FULL_HELP_FLAG[] = "-h";

//-----------------------------------------------------
//!Enters square equation solver mode
//-----------------------------------------------------

void square_mode(void);

//-----------------------------------------------------
//!Enters linear equation solver mode
//-----------------------------------------------------

void linear_mode(void);

//-----------------------------------------------------
//!Enters file input/output mode
//-----------------------------------------------------

void file_mode(const char * const input_file_name,
               const char * const output_file_name);

//-----------------------------------------------------
//!Shows short help for file mode (-f flag)
//!
//!@param [in]  program_name Name of program received
//!                          on standart input
//-----------------------------------------------------

void short_file_help(const char * const program_name);

//-----------------------------------------------------
//!Does tests of solve functions of program
//-----------------------------------------------------

void unit_tests_mode(void);

//-----------------------------------------------------
//!Shows full information about program
//!
//!@param [in]  program_name Name of program received
//!                          on standart input
//-----------------------------------------------------

void full_help(const char * const program_name);

//-----------------------------------------------------
//!Shows short help
//!
//!@param [in]  program_name Name of program received
//!                          on standart input
//-----------------------------------------------------

void short_help(const char * const program_name);
