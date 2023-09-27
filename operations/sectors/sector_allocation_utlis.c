#include "../../include/sectors/sector_allocation_utils.h"

#include <stdio.h>
#include <stdbool.h>
#include "../../include/sectors/sectors.h"
#include "../../include/types/file_static_header.h"
#include "../../include/utils/static_header_utils.h"

/*
 * Returns
 * -1 - cannot allocate
 * number - sector number
 */
uint32_t allocate_sector(FILE* file, int alloc_size, uint32_t prev_sector, uint32_t next_sector) {
    // TODO(Make allocation of sectors dynamic, now writing only at the end)
    struct StaticFileHeader static_header;
    int read_result = read_static_header(file, &static_header);
    if (read_result < 0) return -1;
    uint32_t free_sector = static_header.first_at_end_free;
    static_header.first_at_end_free = free_sector + alloc_size;

    struct SectorHeader header;
    header.is_taken = true;
    header.sectors_taken_in_row = alloc_size;
    header.previous_sector_number = prev_sector; // Set appropriate values
    header.next_sector_number = next_sector; // Set appropriate values

    // Write the updated header to the file
    fseek(file, free_sector * sizeof(union SectorData), SEEK_SET);
    fwrite(&header, sizeof(struct SectorHeader), 1, file);
    write_static_header(file, &static_header);

    return free_sector;
}

void deallocate_sector(FILE* file, uint32_t sector_number) {
    //TODO(Tracking of free sectors)
    struct SectorHeader header;
    fseek(file, sector_number * sizeof(union SectorData), SEEK_SET);
    fread(&header, sizeof(struct SectorHeader), 1, file);

    header.is_taken = false;

    fseek(file, sector_number * sizeof(union SectorData), SEEK_SET);
    fwrite(&header, sizeof(struct SectorHeader), 1, file);
}
