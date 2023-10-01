#include "tests.h"

int init_and_debug_table() {
    // Create file
    FILE* file = fopen("test2.bin", "wb+");

    create_file_and_init_empty_structure(file);

    // Create table
    // Future body of create_table_function
    struct TableScheme table1scheme;
    init_table_scheme(file, "table1", 3, &table1scheme);
    schema_set_column(file, &table1scheme, 1, TABLE_TYPE_INT, "id");
    schema_set_column(file, &table1scheme, 2, TABLE_TYPE_BOOL, "value");
    schema_set_column(file, &table1scheme, 3, TABLE_TYPE_VARCHAR, "string");

    debug_table_indices(file);
    debug_table_info(file, "table1");
    debug_schema_columns(file, "table1");

    return 0;
}
