#include "tests.h"

int check_write_data() {

    FILE* file = fopen("test3.bin", "wb+");
    create_file_and_init_empty_structure(file);
    char* test_string = "TEst STring";

    int wr_res = write_data_to_sector(file, test_string, strlen(test_string), 1);
    printf("%s - result %d\n", test_string, wr_res);
    char* read = (char *) read_data_from_sector(file, test_string, strlen(test_string), 1);
    printf("%s\n", read);
    return 0;
}
