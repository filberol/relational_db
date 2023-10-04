#include "../../include/sectors/sector_utils.h"

/*
 * Returns
 * -1 - cannot allocate
 * number - sector number
 */
uint32_t allocate_sector(FILE *file, size_t alloc_size) {
    // TODO(Make allocation of sectors dynamic, now writing only at the end)
    // Read static header
    struct StaticFileHeader static_header;
    int read_result = read_static_header(file, &static_header);
    if (read_result < 0) return -1;
    uint32_t header_ptr_free = static_header.first_at_end_free;
    uint32_t last_sector = static_header.last_sector;

    // First allocation
    if (last_sector == TABLE_INDEX_HASH_EMPTY) {
//        printf("Writing sector first time at %d\n", header_ptr_free);
        // Write sector
        struct SectorHeader header;
        header.is_taken = true;
        header.sectors_taken_in_row = alloc_size;
        header.prev_sector_number = TABLE_INDEX_HASH_EMPTY;
        header.next_sector_number = -1; // Set appropriate values
        write_sector_header_by_index(file, header_ptr_free, &header);

        // Write header
        static_header.last_sector = header_ptr_free;
        static_header.first_at_end_free = header_ptr_free + alloc_size;
        write_static_header(file, &static_header);

        return header_ptr_free;
    } else {
//        printf("Adding new sector at %d\n", header_ptr_free);
        // Change last sector header
        struct SectorHeader last_header;
        read_sector_header_by_index(file, last_sector, &last_header);
        last_header.next_sector_number = header_ptr_free;
        write_sector_header_by_index(file, last_sector, &last_header);

        // Write new sector
        struct SectorHeader header;
        header.is_taken = true;
        header.sectors_taken_in_row = alloc_size;
        header.prev_sector_number = last_sector;
        header.next_sector_number = -1; // Set appropriate values
        write_sector_header_by_index(file, header_ptr_free, &header);

        // Write header
        static_header.last_sector = header_ptr_free;
        static_header.first_at_end_free = header_ptr_free + alloc_size;
        write_static_header(file, &static_header);

        return header_ptr_free;
    }
}

void deallocate_sector(FILE *file, uint32_t sector_number) {
    // TODO(Tracking of free sectors)
    struct SectorHeader header;
    read_sector_header_by_index(file, sector_number, &header);

    header.is_taken = false;

    // Rewrite sector data
    write_sector_header_by_index(file, sector_number, &header);
}
