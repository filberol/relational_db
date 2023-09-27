#include "../../include/utils/table_schema_utils.h"

struct TableSchema build_empty_schema() {
    struct TableSchema new_schema;
    new_schema.id = 1;
    strcpy(new_schema.name, "empty");
    // No init columns, builder pattern
    return new_schema;
}
