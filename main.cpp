#include <string.h>
#include "./source/headers/modes.h"


int main(unsigned int argc, const char * argv[]) {
    unsigned int mode_number = choosing_mode(argc, argv);

    //while (argc > 0) {

    //}

    switch (mode_number) {
        case SQUARE:
            run_square_mode();
            break;
        case LINEAR:
            run_linear_mode();
            break;
        case FILE_IO:
            file_io_mode(argv[2], argv[3]);
            break;
        case FILE_I:
            file_io_mode(argv[2], "");
            break;
        case FILE_HELP:
            show_file_help(argv[0]);
            break;
        case UNIT_TESTS:
            run_unit_tests_mode(argc, argv);
            break;
        case FULL_HELP:
            show_full_help(argv[0]);
            break;
        default:
            show_short_help(argv[0]);
            break;
    }


    return 0;
}
