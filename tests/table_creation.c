#include "tests.h"

int init_and_debug_table() {
    // Create file
    FILE* file = fopen("test2.bin", "wb+");

    create_file_and_init_empty_structure(file);

//    struct StaticFileHeader def_header = create_file_header(10, 5, 1);
//    write_static_header(file, &def_header);
//
//    // Allocate sector
//    int sectors_needed = (sizeof(struct TableIndexArray) + sizeof(struct SectorHeader) + 100) / SECTOR_SIZE;
//    allocate_sector(file, sectors_needed);
//    struct TableIndexArray* global_index_array = allocate_empty_table_index();
//    write_table_index_to_sector(file, def_header.table_indices_sector, global_index_array);

    // Create table
    // Future body of create_table_function
    struct TableScheme table1scheme;
    init_table_scheme(file, "table1", 3, &table1scheme);
    schema_set_column(file, &table1scheme, 1, TABLE_TYPE_INT, "id");
    schema_set_column(file, &table1scheme, 2, TABLE_TYPE_BOOL, "value");
    schema_set_column(file, &table1scheme, 3, TABLE_TYPE_VARCHAR, "string");

    debug_table_indices(file);

    debug_table_info(file, "table1");

//    debug_table_info();
//    debug_schema_columns();


//    add_table_index(file, )

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
