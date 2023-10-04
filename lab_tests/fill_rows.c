#include "tests.h"

int fill_rows() {
    FILE* file = fopen("test2.bin", "wb+");
    create_file_and_init_empty_structure(file);

    struct TableScheme table1scheme;
    init_table_scheme(file, "table1", 3, &table1scheme);
    schema_set_column(file, &table1scheme, 1, TABLE_TYPE_INT, "id");
    schema_set_column(file, &table1scheme, 2, TABLE_TYPE_BOOL, "value");
    schema_set_column(file, &table1scheme, 3, TABLE_TYPE_VARCHAR, "string");

    int id = 1;
    bool val = true;
    char* str = "test_string";
    union TableCellWithData table1row[table1scheme.columns_count];
    row_set_cell_value(file, &table1scheme, table1row, 1, TABLE_TYPE_INT, &id);
    row_set_cell_value(file, &table1scheme, table1row, 2, TABLE_TYPE_BOOL, &val);
    row_set_cell_value(file, &table1scheme, table1row, 3, TABLE_TYPE_VARCHAR, str);
    add_row_to_file(file, &table1scheme, table1row);

    // TODO(Code debug_table method)
    print_cell_value(file, TABLE_TYPE_VARCHAR, (void *) &table1row[2]);

    return 0;
}
