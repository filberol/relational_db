#include "../include/debug/debug_utils.h"

char* cell_type_to_string(enum CellType cell) {
    switch (cell) {
        case TABLE_TYPE_INT: return "Int";
        case TABLE_TYPE_BIGINT: return "BigInt";
        case TABLE_TYPE_VARCHAR: return "VarChar";
        case TABLE_TYPE_FLOAT: return "Float";
        case TABLE_TYPE_BOOL: return "Bool";
        case TABLE_TYPE_EMPTY: return "None";
    }
}

void debug_static_header(FILE* file) {
    struct StaticFileHeader read_header;
    int readResult = read_static_header(file, &read_header);

    if (readResult == 0) {
        printf("Header read from the beginning of the file:\n");
        printf("Table Count: %d\n", read_header.table_count);
        printf("Sector Table Count: %d\n", read_header.table_indices_sector);
        printf("First sector at end free: %d\n", read_header.first_at_end_free);
    } else {
        printf("Error reading header from the beginning of the file.\n");
    }
}

void debug_table_indices(FILE* file) {
    struct StaticFileHeader header;
    read_static_header(file, &header);
    struct TableIndexArray* table_index = allocate_empty_table_index();
    read_table_index_from_sector(file, header.table_indices_sector, table_index);
    printf("Tables found\n");
    for (int i = 0; i < MAX_TABLES_COUNT; i++) {
        if (table_index->table_map[i].table_name_hash != TABLE_INDEX_HASH_EMPTY) {
            struct TableIndex index = table_index->table_map[i];
            printf("Hash: %d\tSector: %d\n", index.table_name_hash, index.schema_sector);
        }
    }
}

void debug_file_sectors_from_first() {
    // TODO(Finish dynamic allocation with linked list)
}

void debug_table_info(FILE* file, const char* table_name) {
    struct StaticFileHeader header;
    read_static_header(file, &header);

    uint32_t schema_sector = find_table_sector(header.table_indices_sector, file, table_name);
    struct TableScheme scheme;
    read_data_from_sector(file, &scheme, sizeof(struct TableScheme), schema_sector);

    printf("Table scheme sector %d\n", schema_sector);
    printf("Name: %s\n", scheme.name);
    printf("Columns count: %d\n", scheme.columns_count);
}

void debug_schema_columns(FILE* file, const char* table_name) {
    struct StaticFileHeader header;
    read_static_header(file, &header);

    uint32_t schema_sector = find_table_sector(header.table_indices_sector, file, table_name);
    struct TableScheme scheme;
    read_data_from_sector(file, &scheme, sizeof(struct TableScheme), schema_sector);

    int col_count = scheme.columns_count;
    struct HeaderCell headers[col_count];
    read_data_from_sector(file, &headers, sizeof(struct HeaderCell) * col_count, scheme.columns_info_sector);

    for (int i = 0; i < col_count; i++) {
        printf("Column %s\t type %s\n", headers[i].column_name, cell_type_to_string(headers[i].meta.cell_type));
    }
}
