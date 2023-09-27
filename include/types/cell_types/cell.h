#ifndef LAB1LLP_CELL_H
#define LAB1LLP_CELL_H

#include "../column_types.h"

struct TableCell {
    enum CellType cell_type;
};

struct HeaderCell {
    struct TableCell meta;
    char column_name[COLUMN_MAX_NAME_LENGTH];
};

#endif //LAB1LLP_CELL_H
