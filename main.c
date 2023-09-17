#include <stdio.h>
#include "tests/tests.h"

int main() {
    printf("\tTest 1 - Read and write header\n");
    test_header();
    printf("\tTest 2 - Does allocating change header\n");
    test_alloc();
    return 0;
}
