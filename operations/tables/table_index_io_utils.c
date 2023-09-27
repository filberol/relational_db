#include "../../include/utils/table_index_utils.h"

/*
 * Returns
 * -1 - error
 * 0 - ok
 */
int read_table_index_from_sector(FILE *file, uint32_t sector_number, struct TableIndexArray *table_index) {
    fseek(file, sector_number * SECTOR_SIZE + sizeof(struct SectorHeader), SEEK_SET);
    return fread(table_index, sizeof(struct TableIndexArray), 1, file) - 1;
}

/*
 * Returns
 * -1 - error
 * 0 - ok
 */
int write_table_index_to_sector(FILE *file, uint32_t sector_number, struct TableIndexArray *table_index) {
    fseek(file, sector_number * SECTOR_SIZE + sizeof(struct SectorHeader), SEEK_SET);
    return fwrite(table_index, sizeof(struct TableIndexArray), 1, file) - 1;
}
