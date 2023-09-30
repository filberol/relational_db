#include "tests.h"

int init_and_debug_table() {
    // Create file
    FILE* file = fopen("test2.bin", "wb+");

    create_file_and_init_empty_structure(file);


//    add_table_index(file, "table1", table1_schema, global_index_array);
//    add_table_index(file, "table2", table2_schema, global_index_array);
//
//    struct TableIndexArray copy_from_file;
//    read_table_index_from_sector(file, header.table_indices_sector, &copy_from_file);
//
//    printf("Default global malloced ");
//    debug_table_indices(global_index_array);
//    printf("Copied from file manually ");
//    debug_table_indices(&copy_from_file);
//
//    uint32_t table3_schema = allocate_sector(file, 20);
//    remove_table_index(file, "table2", global_index_array);
//    update_table_sector_link(file, "table1", table3_schema, global_index_array);
//    read_table_index_from_sector(file, header.table_indices_sector, &copy_from_file);
//    printf("Modified ");
//    debug_table_indices(&copy_from_file);
    return 0;
}
