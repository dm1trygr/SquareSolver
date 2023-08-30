#include <stdio.h>
#include <string.h>
#include "./source/headers/modes.h"


int main(unsigned const int argc, const char * argv[]) {
    unsigned int mode_number = choosing_mode(argc, argv);

    if (mode_number != FULL_HELP &&
        mode_number != SHORT_HELP &&
        mode_number != FILE_HELP) {
        printf("Welcome to Square equation solver\n"
               "This program can solve square equations\n\n"
               "CURRENT MODE: ");
        switch (mode_number) {
            case SQUARE:
                printf("Square equations\n\n");
                run_square_mode();
                break;
            case LINEAR:
                printf("Linear equations\n\n");
                run_linear_mode();
                break;
            case FILE_IO:
                printf("File input/output\n\n");
                file_io_mode(argv[2], argv[3]);
                break;
            case FILE_I:
                printf("File input/output\n\n");
                file_io_mode(argv[2], "");
                break;
            case UNIT_TESTS:
                printf("Unit tests\n\n");
                run_unit_tests_mode(argc, argv);
                break;
            default:
                printf("Unknown\n\n");
                show_short_help(argv[0]);

        }
        printf("Goodbye!\n");
    }
    else {
        switch (mode_number) {
            case FULL_HELP:
                show_full_help(argv[0]);
                break;
            case FILE_HELP:
                show_file_help(argv[0]);
                break;
            default:
                show_short_help(argv[0]);
        }
    }

    return 0;
}
