#ifndef LAB1LLP_SECTOR_UTILS_H
#define LAB1LLP_SECTOR_UTILS_H

#include <stdio.h>
#include "../../include/types/table_index.h"
#include "../../consts/sector_consts.h"
#include "../../include/sectors/sectors.h"

void read_table_index_from_sector(FILE* file, uint32_t sector_number, struct TableIndexArray* table_index);
void write_table_index_to_sector(FILE* file, uint32_t sector_number, struct TableIndexArray* table_index);

#endif //LAB1LLP_SECTOR_UTILS_H
