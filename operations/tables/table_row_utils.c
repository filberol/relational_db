#include "../../include/tables/table_row_utils.h"

/*
 * Returns
 * -1 - wrong args
 * 0 - ok
 */
int row_set_cell_value(
        FILE *file, const struct TableScheme *scheme, union TableCellWithData *rows, int col_num,
        enum CellType cell_type, void *value
) {
    if (col_num > scheme->columns_count) return -1;
    int col = col_num - 1;

    switch (cell_type) {
        case TABLE_TYPE_INT:
            rows[col].int_c.meta.cell_type = cell_type;
            rows[col].int_c.value = *(int *) value;
            break;
        case TABLE_TYPE_BIGINT:
            rows[col].bigint_c.meta.cell_type = cell_type;
            rows[col].bigint_c.value = *(int64_t *) value;
            break;
        case TABLE_TYPE_VARCHAR:
            rows[col].string_c.meta.cell_type = cell_type;
            size_t str_size = strlen((char *) value);
            uint32_t sector = write_string_to_sector(file, (char *) value);
            rows[col].string_c.string_size = str_size;
            rows[col].string_c.string_value_sector = sector;
            break;
        case TABLE_TYPE_FLOAT:
            rows[col].float_c.meta.cell_type = cell_type;
            rows[col].float_c.value = *(float *) value;
            break;
        case TABLE_TYPE_BOOL:
            rows[col].bool_c.meta.cell_type = cell_type;
            rows[col].bool_c.value = *(bool *) value;
            break;
        case TABLE_TYPE_EMPTY:
            break;
    }
    return 0;
}

int add_row_to_file(FILE *file, struct TableScheme *scheme, union TableCellWithData *rows) {
    size_t row_size = sizeof(union TableCellWithData) * scheme->columns_count;
    size_t sectors_size = calculate_sectors_needed(row_size);
    uint32_t allocated_sector = allocate_sector(file, sectors_size);

    // Write row
    write_data_to_sector(file, rows, row_size, allocated_sector);

    // Change sector headers links
    if (scheme->data_first_sector == TABLE_INDEX_HASH_EMPTY) {
        // Nothing to change in headers, no links
        scheme->data_first_sector = allocated_sector;
        scheme->data_last_sector = allocated_sector;
    } else {
        // Make links for two sectors
        struct SectorHeader last_row_header;
        struct SectorHeader new_last_row_header;
        // Read last and new last
        read_sector_header_by_index(file, scheme->data_last_sector, &last_row_header);
        read_sector_header_by_index(file, allocated_sector, &new_last_row_header);
        // New links
        last_row_header.next_logical_data_sector = allocated_sector;
        new_last_row_header.prev_logical_data_sector = scheme->data_last_sector;
        // Save in same place
        write_sector_header_by_index(file, scheme->data_last_sector, &last_row_header);
        write_sector_header_by_index(file, allocated_sector, &new_last_row_header);
    }

    // Change scheme signature
    scheme->data_last_sector = allocated_sector;
    write_data_to_sector(file, scheme, sizeof(struct TableScheme), scheme->own_sector);

    return 0;
}

void print_cell_value(FILE *file, enum CellType cell_type, void *value) {
    union TableCellWithData cell = *(union TableCellWithData *) value;
    switch (cell_type) {
        case TABLE_TYPE_INT:
        case TABLE_TYPE_BIGINT:
            printf("%d", cell.int_c.value);
            break;
        case TABLE_TYPE_VARCHAR: {
            struct StringTableCell val = cell.string_c;
            print_string_from_sector(file, val.string_value_sector, val.string_size);
            break;
        }
        case TABLE_TYPE_FLOAT:
            printf("%.2f", cell.float_c.value);
            break;
        case TABLE_TYPE_BOOL:
            printf(cell.bool_c.value ? "true" : "false");
            break;
        case TABLE_TYPE_EMPTY:
            printf("NaN");
            break;
    }
}
