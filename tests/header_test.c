#include "tests.h"

#include <stdio.h>
#include "../include/types/file_static_header.h"
#include "../include/utils/static_header_utils.h"
#include "../include/debug/debug_utils.h"

int test_header() {
    struct StaticFileHeader def_header = create_file_header(10, 5, 1);


    FILE *file = fopen("test.bin", "wb+");
    write_static_header(file, &def_header);


    debug_static_header(file);
    fclose(file);

    return 0;
}
