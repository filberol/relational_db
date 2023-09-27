#include <stdio.h>
#include "../../include/types/table_index.h"
#include "../../consts/sector_consts.h"
#include "../../include/sectors/sectors.h"

void read_table_index_from_sector(FILE* file, uint32_t sector_number, struct TableIndexArray* table_index) {
    fseek(file, sector_number * SECTOR_SIZE + sizeof(struct SectorHeader), SEEK_SET);
    fread(table_index, sizeof(struct TableIndexArray), 1, file);
}

void write_table_index_to_sector(FILE* file, uint32_t sector_number, struct TableIndexArray* table_index) {
    fseek(file, sector_number * SECTOR_SIZE + sizeof(struct SectorHeader), SEEK_SET);
    fwrite(table_index, sizeof(struct TableIndexArray), 1, file);
}
