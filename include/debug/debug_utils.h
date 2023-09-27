#ifndef LAB1LLP_DEBUG_UTILS_H
#define LAB1LLP_DEBUG_UTILS_H

#include <stdio.h>
#include <stdint.h>
#include "../../include/types/file_static_header.h"
#include "../../include/utils/static_header_utils.h"
#include "../../include/types/table_index.h"
#include "../../consts/table_consts.h"
#include "../../consts/hash_consts.h"

void debug_static_header(FILE* file);
void debug_table_indices(struct TableIndexArray* table_index);

#endif //LAB1LLP_DEBUG_UTILS_H
