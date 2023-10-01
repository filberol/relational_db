#include <stdio.h>
#include "tests/tests.h"

int main() {
    printf("\tTest 1 - Read and write header\n");
    test_header();
    printf("\tTest 2 - Does allocating change header\n");
    test_alloc();
    printf("\tTest 3 - Trying to read something from sector\n");
    check_sector_write();
    printf("\tTest 4 - Are table indices synchronized?\n");
    check_table_indices_update();
    printf("\tTest 5 - Writing data to sector\n");
    check_write_data();
    printf("\tTest 6 - Are tables saved correctly\n");
    init_and_debug_table();
    return 0;
}
