#include "../../include/tables/table_row_utils.h"

/*
 * Returns
 * -1 - wrong args
 * 0 - ok
 */
int row_set_value(
        FILE* file, const struct TableScheme *scheme, union TableCellWithData *rows, int col_num,
        enum CellType cell_type, void *value
) {
    if (col_num > scheme->columns_count) return -1;

    switch (cell_type) {
        case TABLE_TYPE_INT:
            rows[col_num].int_c.meta.cell_type = cell_type;
            rows[col_num].int_c.value = *(int *) value;
            break;
        case TABLE_TYPE_BIGINT:
            rows[col_num].bigint_c.meta.cell_type = cell_type;
            rows[col_num].bigint_c.value = *(int64_t *) value;
            break;
        case TABLE_TYPE_VARCHAR:
            rows[col_num].string_c.meta.cell_type = cell_type;
            size_t str_size = strlen((char *) value);
            uint32_t sector = write_string_to_file(file, (char *) value);
            rows[col_num].string_c.string_size = str_size;
            rows[col_num].string_c.string_value_sector = sector;
            break;
        case TABLE_TYPE_FLOAT:
            rows[col_num].float_c.meta.cell_type = cell_type;
            rows[col_num].float_c.value = *(float *) value;
            break;
        case TABLE_TYPE_BOOL:
            rows[col_num].bool_c.meta.cell_type = cell_type;
            rows[col_num].bool_c.value = *(bool *) value;
            break;
        case TABLE_TYPE_EMPTY:
            break;
    }
    return 0;
}

