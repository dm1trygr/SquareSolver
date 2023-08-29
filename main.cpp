#include <string.h>
#include "./source/headers/modes.h"


int main(int argc, char * argv[]) {
    if (argc >= 2) {
        if (strcmp(argv[1], SQUARE_MODE_FLAG) == 0) {
            run_square_mode();
        }
        else if (strcmp(argv[1], LINEAR_MODE_FLAG) == 0) {
            run_linear_mode();
        }
        else if (strcmp(argv[1], FILE_MODE_FLAG) == 0) {
            if (argc >= 4) {
                file_io_mode(argv[2], argv[3]);
            }
            else {
                show_file_help(argv[0]);
            }
        }
        else if (strcmp(argv[1], UNIT_TESTS_FLAG) == 0) {
            run_unit_tests_mode();
        }
        else if (strcmp(argv[1], FULL_HELP_FLAG) == 0) {
            show_full_help(argv[0]);
        }
        else {
            show_short_help(argv[0]);
        }
    }
    else {
        show_short_help(argv[0]);
    }

    return 0;
}
