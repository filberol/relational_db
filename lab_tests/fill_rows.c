#include "tests.h"

int fill_rows() {
    FILE* file = fopen("test2.bin", "wb+");
    create_file_and_init_empty_structure(file);

    struct TableScheme table1scheme;
    init_table_scheme(file, "table1", 3, &table1scheme);
    schema_set_column(file, &table1scheme, 1, TABLE_TYPE_INT, "id");
    schema_set_column(file, &table1scheme, 2, TABLE_TYPE_BOOL, "value");
    schema_set_column(file, &table1scheme, 3, TABLE_TYPE_VARCHAR, "string");

    union TableCellWithData table1row[table1scheme.columns_count];

    return 0;
}
