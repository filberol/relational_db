#include "tests.h"

int check_write_data() {

    FILE* file = fopen("test3.bin", "wb+");
    create_file_and_init_empty_structure(file);
    char test_string[1024] = "TEst STring";
    char test_buff[1024];
    size_t buff_size = sizeof(test_string);

    uint32_t free_sector = allocate_sector(file, 3);
    printf("Allocated sector %d\n", free_sector);
    int wr_res = write_data_to_sector(file, test_string, buff_size, free_sector);
    printf("Writing %s - result %d\n", test_string, wr_res);
    int re_res = read_data_from_sector(file, test_buff, buff_size, free_sector);
    printf("Reading %s - result %d\n", test_buff, re_res);
    return 0;
}
