#ifndef MODES_HEADER
#define MODES_HEADER

const char SQUARE_MODE_FLAG[] = "-s";
const char LINEAR_MODE_FLAG[] = "-l";
const char FILE_MODE_FLAG[] = "-f";
const char UNIT_TESTS_FLAG[] = "-t";
const char FULL_HELP_FLAG[] = "-h";

//-----------------------------------------------------
//!Depending on the flag calls the function with the
//!required program mode
//!
//!@param [in]  argc   Amount of arguments + name of
//!                    program
//!@param [in]  argv   Array with name of program and
//!                    arguments
//!
//!@see run_square_mode(), run_linear_mode(),
//!     file_io_mode(), show_file_help(),
//!     run_unit_tests_mode(), show_full_help(),
//!     show_short_help()
//-----------------------------------------------------

void choosing_mode(const int argc, const char* argv[]);

//-----------------------------------------------------
//!Enters square equation solver mode
//-----------------------------------------------------

void run_square_mode(void);

//-----------------------------------------------------
//!Enters linear equation solver mode
//-----------------------------------------------------

void run_linear_mode(void);

//-----------------------------------------------------
//!Reads coefficients from file and writes solutions to
//!other file
//!
//!@param [in]  input_file_name  Name of input file
//!@param [out] output_file_name Name of output file
//-----------------------------------------------------

void file_io_mode(const char* const input_file_name,
                  const char* const output_file_name);

//-----------------------------------------------------
//!Shows short help for file mode (-f flag)
//!
//!@param [in]  program_name Name of program received
//!                          on standard input
//-----------------------------------------------------

void show_file_help(const char* const program_name);

//-----------------------------------------------------
//!Does tests of solve functions of program
//!
//!@param [in]  argc   Amount of arguments + name of
//!                    program
//!@param [in]  argv   Array with name of program and
//!                    arguments
//-----------------------------------------------------

void run_unit_tests_mode(const int argc, const char* argv[]);

//-----------------------------------------------------
//!Shows full information about program
//!
//!@param [in]  program_name Name of program received
//!                          on standard input
//-----------------------------------------------------

void show_full_help(const char* const program_name);

//-----------------------------------------------------
//!Shows short help
//!
//!@param [in]  program_name Name of program received
//!                          on standard input
//-----------------------------------------------------

void show_short_help(const char* const program_name);

#endif
