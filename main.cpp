#include <stdio.h>
#include <math.h>
#include <float.h>       // пересмотреть инклюды
#include <string.h>
#include "modes.h"


int main(int argc, char * argv[]) {  // вместо -flag [option]
    if (argc == 2) {
        if (strcmp(argv[1], SQUARE_MODE_FLAG) == 0) { // некорректный ввод начинающийс€ с числа
            square_mode();  // equation удалить изщ названги€€
        }
        else if (strcmp(argv[1], LINEAR_MODE_FLAG) == 0) {
            linear_mode();
        }
        else if (strcmp(argv[1], FILE_MODE_FLAG) == 0) {
            if (argc == 4) {
                file_mode(argv[2], argv[3]);
            }
            else {
                short_file_help(argv[0]);
            }
        }  // file_mode непон€тно, лучше помен€ть
        // отдельна€ функци€ дл€ работы с файлами и еще функци€ дл€ работы с stdin и stdout через пред. ф.
        else if (strcmp(argv[1], UNIT_TESTS_FLAG) == 0) {
            unit_tests_mode();
        }
        else if (strcmp(argv[1], FULL_HELP_FLAG) == 0) {
            full_help(argv[0]);
        }
        else {
            short_help(argv[0]);
        }
    }
    else {
        short_help(argv[0]);
    }

    return 0;
}

// в readme как установить и как использовать (1пример использовани€)
// разбить по дирекори€м .h и .cpp
