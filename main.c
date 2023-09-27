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
    return 0;
}
