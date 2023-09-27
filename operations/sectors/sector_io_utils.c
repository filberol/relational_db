#include "../../include/sectors/sector_utils.h"

// Leave padding for sector header and data to avoid crossing in case of packing
// Just overthinking
size_t calculate_sectors_needed(size_t struct_size) {
    // Integer division, then always cover the leftovers with one sector
    return (struct_size + sizeof (struct SectorHeader) + SECTOR_TO_DATA_MARGIN) / SECTOR_SIZE + 1;
}

/*
 * Returns
 * -3 - Struct bigger than sector capacity
 * number - sector number
 */
int write_data_to_sector(void* data_ptr, size_t buffer_size) {
    struct SectorHeader;
    // TODO
    return 0;
}
