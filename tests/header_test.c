#include "tests.h"

#include <stdio.h>
#include "../include/types/file_static_header.h"
#include "../include/utils/static_header_utils.h"
#include "../include/debug/debug_utils.h"

int test_header() {
    struct StaticFileHeader def_header = create_file_header(10, 5, 1);

    FILE *file = fopen("test.bin", "wb+");
    if (file != NULL) {
        int write_result = write_static_header(file, &def_header);
        if (write_result == 0) {
            printf("Header successfully written to the beginning of the file.\n");
        } else {
            printf("Error writing header to the beginning of the file.\n");
        }
    } else {
        printf("Error opening file for writing.\n");
    }

    debug_static_header(file);
    fclose(file);

    return 0;
}
