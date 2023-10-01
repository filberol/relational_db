#include "../../include/sectors/sector_utils.h"

/*
 * Returns
 * -1 - cannot allocate
 * number - sector number
 */
uint32_t allocate_sector(FILE* file, size_t alloc_size) {
    // TODO(Make allocation of sectors dynamic, now writing only at the end)
    struct StaticFileHeader static_header;
    int read_result = read_static_header(file, &static_header);
    if (read_result < 0) return -1;
    uint32_t free_sector = static_header.first_at_end_free;
    static_header.first_at_end_free = free_sector + alloc_size;

    struct SectorHeader header;
    header.is_taken = true;
    header.sectors_taken_in_row = alloc_size;
    header.previous_sector_number = -1; // Set appropriate values
    header.next_sector_number = -1; // Set appropriate values

    // Write the updated header to the file
    write_sector_header_by_index(file, free_sector, &header);
    write_static_header(file, &static_header);

    return free_sector;
}

void deallocate_sector(FILE* file, uint32_t sector_number) {
    // TODO(Tracking of free sectors)
    struct SectorHeader header;
    read_sector_header_by_index(file, sector_number, &header);

    header.is_taken = false;

    // Rewrite sector data
    write_sector_header_by_index(file, sector_number, &header);
}
