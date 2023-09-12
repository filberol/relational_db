#ifndef LAB1LLP_TABLE_SCHEMA_H
#define LAB1LLP_TABLE_SCHEMA_H

#include <stdint.h>
#include "../../../consts/table_consts.h"

#include "../cell_types/bigint_cell.h"
#include "../cell_types/bool_cell.h"
#include "../cell_types/float_cell.h"
#include "../cell_types/int_cell.h"
#include "../cell_types/string_cell.h"

union TableColumn {
    struct BigIntTableCell bigint_c;
    struct BoolTableCell bool_c;
    struct FloatTableCell float_c;
    struct IntTableCell int_c;
    struct StringTableCell string_c;
};

struct TableSchema {
    int id;
    char name[TABLE_MAX_NAME_LENGTH];
    uint32_t data_first_sector;
    union TableColumn columns[TABLE_MAX_COLUMNS];
};



#endif //LAB1LLP_TABLE_SCHEMA_H
