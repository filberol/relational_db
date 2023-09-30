#include "tests.h"

int check_table_indices_update() {
    // Create file
    struct StaticFileHeader def_header = create_file_header(10, 5, 1);
    FILE* file = fopen("test2.bin", "wb+");
    write_static_header(file, &def_header);

    // Allocate sector
    int sectors_needed = (sizeof(struct TableIndexArray) + sizeof(struct SectorHeader) + 100) / SECTOR_SIZE;
    allocate_sector(file, sectors_needed);


    // From here act as existing table
    // Create and synchronize table indices
    struct StaticFileHeader header;
    read_static_header(file, &header);
    struct TableIndexArray* global_index_array = allocate_empty_table_index();

    // stub creating table
    uint32_t table1_schema = allocate_sector(file, 10);
    uint32_t table2_schema = allocate_sector(file, 20);

    add_table_index(file, "table1", table1_schema, global_index_array);
    add_table_index(file, "table2", table2_schema, global_index_array);

    struct TableIndexArray copy_from_file;
    read_table_index_from_sector(file, header.table_indices_sector, &copy_from_file);

    printf("Default global malloced ");
    debug_table_indices(global_index_array);
    printf("Copied from file manually ");
    debug_table_indices(&copy_from_file);

    uint32_t table3_schema = allocate_sector(file, 20);
    remove_table_index(file, "table2", global_index_array);
    update_table_sector_link(file, "table1", table3_schema, global_index_array);
    read_table_index_from_sector(file, header.table_indices_sector, &copy_from_file);
    printf("Modified ");
    debug_table_indices(&copy_from_file);

    return 0;
}
