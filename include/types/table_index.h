#ifndef LAB1LLP_TABLE_INDEX_H
#define LAB1LLP_TABLE_INDEX_H

#include <stdint.h>
#include "../../consts/table_consts.h"

struct TableIndex {
    char name[TABLE_MAX_NAME_LENGTH];
    uint32_t schema_sector;
};

struct TableIndexArray {
    struct TableIndex table_map[MAX_TABLES_COUNT];
};

#endif //LAB1LLP_TABLE_INDEX_H
