#include "../../include/sectors/sector_utils.h"

void read_table_index_from_sector(FILE* file, uint32_t sector_number, struct TableIndexArray* table_index) {
    fseek(file, sector_number * SECTOR_SIZE + sizeof(struct SectorHeader), SEEK_SET);
    fread(table_index, sizeof(struct TableIndexArray), 1, file);
}

void write_table_index_to_sector(FILE* file, uint32_t sector_number, struct TableIndexArray* table_index) {
    fseek(file, sector_number * SECTOR_SIZE + sizeof(struct SectorHeader), SEEK_SET);
    fwrite(table_index, sizeof(struct TableIndexArray), 1, file);
}
