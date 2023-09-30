#include "tests.h"

int test_alloc() {
    struct StaticFileHeader def_header = create_file_header(10, 5, 1);
    FILE* file = fopen("test2.bin", "wb+");
    write_static_header(file, &def_header);

    uint32_t alloc = allocate_sector(file, 3);
    uint32_t alloc2 = allocate_sector(file, 3);
    printf("Allocated sectors %d and %d\n", alloc, alloc2);

    fclose(file);

    return 0;
}
