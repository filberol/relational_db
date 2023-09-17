#include "../include/debug/debug_utils.h"

#include <stdio.h>
#include "../include/types/file_static_header.h"
#include "../include/utils/static_header_utils.h"

void debug_static_header(FILE* file) {
    struct StaticFileHeader read_header;
    int readResult = read_static_header(file, &read_header);

    if (readResult == 0) {
        printf("Header read from the beginning of the file:\n");
        printf("Table Count: %d\n", read_header.table_count);
        printf("Sector Table Count: %d\n", read_header.table_indices_sector);
        printf("First sector at end free: %d\n", read_header.first_at_end_free);
    } else {
        printf("Error reading header from the beginning of the file.\n");
    }
}

void debug_table_indices_from_sector(FILE* file, uint32_t sector) {

}
