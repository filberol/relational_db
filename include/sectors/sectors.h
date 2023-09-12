#ifndef LAB1LLP_SECTORS_H
#define LAB1LLP_SECTORS_H

#include <stdbool.h>
#include <stdint.h>
#include "../../consts/sectors.h"

// Sector attributes
struct SectorHeader {
    bool is_taken;
    int sectors_taken_in_row;
    uint32_t next_sector_number;
};

// Sector itself
union SectorData {
    struct SectorHeader status;
    unsigned char data[SECTOR_SIZE];
};

#endif //LAB1LLP_SECTORS_H
