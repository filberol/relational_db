#include "create_static_header.h"
#include "../../include/types/file_static_header.h"

struct StaticFileHeader create_file_header(
        int table_count,
        int table_indices_sector
) {
    struct StaticFileHeader header;
    header.table_count = table_count;
    header.table_indices_sector = table_indices_sector;
    return header;
}

struct StaticFileHeader create_empty_file_header() {
    // No tables, indices from first
    // Static header strictly less than sector size
    return create_file_header(0, 1);
}
