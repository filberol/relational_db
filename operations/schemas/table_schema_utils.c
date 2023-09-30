#include "../../include/tables/table_schema_utils.h"

/*
 * Returns
 * -1 - wrong args
 * 0 - ok
 */
int init_table_scheme(
        FILE* file, const char *table_name, int column_count, struct TableScheme* empty_scheme
) {
    if (strlen(table_name) > TABLE_MAX_NAME_LENGTH) return -1;

    size_t sectors_for_table_meta = calculate_sectors_needed(sizeof(struct TableScheme));
    size_t sectors_for_column_headers = calculate_sectors_needed(sizeof(struct HeaderCell) * column_count);
    uint32_t col_info_sector = allocate_sector(file, sectors_for_table_meta);
    uint32_t data_sector = allocate_sector(file, sectors_for_column_headers);

    strcpy(empty_scheme->name, table_name);
    empty_scheme->columns_count = column_count;
    empty_scheme->columns_info_sector = col_info_sector;
    empty_scheme->data_first_sector = data_sector;
    return 0;
}

int schema_set_column(
        struct TableScheme* schema, int col_num
) {
    return 0;
}
