#ifndef LAB1LLP_TABLE_RAW_UTILS_H
#define LAB1LLP_TABLE_RAW_UTILS_H

#include <string.h>
#include "../../include/types/schema/table_schema.h"
#include "../types/schema/column_types.h"
#include "../../include/utils/file_string_utils.h"

int row_set_value(FILE* file, const struct TableScheme* scheme, union TableCellWithData* rows, int col_num, enum CellType cell_type, void* value);

#endif //LAB1LLP_TABLE_RAW_UTILS_H
