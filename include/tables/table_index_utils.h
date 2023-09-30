#ifndef LAB1LLP_TABLE_INDEX_UTILS_H
#define LAB1LLP_TABLE_INDEX_UTILS_H

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "../types/table_index.h"
#include "../../consts/sector_consts.h"
#include "../sectors/sectors.h"
#include "../utils/hash_utils.h"
#include "../utils/static_header_utils.h"

int read_table_index_from_sector(FILE *file, uint32_t sector_number, struct TableIndexArray *table_index);
int write_table_index_to_sector(FILE *file, uint32_t sector_number, struct TableIndexArray *table_index);
struct TableIndexArray *allocate_empty_table_index();
int add_table_index(FILE *file, const char *table_name, uint32_t data_sector, struct TableIndexArray *index_table);
int update_table_sector_link(FILE *file, const char *table_name, uint32_t new_data_sector, struct TableIndexArray *index_table);
int remove_table_index(FILE *file, const char *table_name, struct TableIndexArray *index_table);

#endif //LAB1LLP_TABLE_INDEX_UTILS_H
