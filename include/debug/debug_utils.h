#ifndef LAB1LLP_DEBUG_UTILS_H
#define LAB1LLP_DEBUG_UTILS_H

#include <stdio.h>
#include <stdint.h>
#include "../../include/types/file_static_header.h"
#include "../../include/utils/static_header_utils.h"
#include "../../include/types/table_index.h"
#include "../../consts/table_consts.h"
#include "../../consts/hash_consts.h"
#include "../../include/tables/table_index_utils.h"
#include "../../include/sectors/sector_utils.h"
#include "../../include/types/schema/table_schema.h"

void debug_static_header(FILE* file);
void debug_table_indices(FILE* file);
void debug_table_info(FILE* file, const char* table_name);
void debug_schema_columns(FILE* file, const char* table_name);

#endif //LAB1LLP_DEBUG_UTILS_H
