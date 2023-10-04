#include "tests.h"

int check_table_indices_update() {
    // Create file
    FILE* file = fopen("test2.bin", "wb+");
    create_file_and_init_empty_structure(file);

    // From here act as existing table
    // Create and synchronize table indices
    struct StaticFileHeader header;
    read_static_header(file, &header);

    // stub creating table
    uint32_t table1_schema = allocate_sector(file, 10);
    uint32_t table2_schema = allocate_sector(file, 20);

    add_table_index(header.table_indices_sector, file, "table1", table1_schema);
    add_table_index(header.table_indices_sector, file, "table2", table2_schema);

    struct TableIndexArray copy_from_file;
    read_table_index_from_sector(file, header.table_indices_sector, &copy_from_file);

    printf("Default global malloced ");
    debug_table_indices(file);

    uint32_t table3_schema = allocate_sector(file, 20);
    remove_table_index(header.table_indices_sector, file, "table2");
    update_table_sector_link(header.table_indices_sector, file, "table1", table3_schema);
    read_table_index_from_sector(file, header.table_indices_sector, &copy_from_file);
    printf("Modified ");
    debug_table_indices(file);

    return 0;
}
