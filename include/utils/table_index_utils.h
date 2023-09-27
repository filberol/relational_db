#ifndef LAB1LLP_TABLE_INDEX_UTILS_H
#define LAB1LLP_TABLE_INDEX_UTILS_H

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "../../include/types/table_index.h"
#include "../../consts/sector_consts.h"
#include "../../include/sectors/sectors.h"
#include "../../include/utils/hash_utils.h"

#define TABLE_HASH_EMPTY UINT32_MAX

int read_table_index_from_sector(FILE *file, uint32_t sector_number, struct TableIndexArray *table_index);
int write_table_index_to_sector(FILE *file, uint32_t sector_number, struct TableIndexArray *table_index);


#endif //LAB1LLP_TABLE_INDEX_UTILS_H
