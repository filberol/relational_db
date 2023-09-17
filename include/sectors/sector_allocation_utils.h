#ifndef LAB1LLP_SECTOR_ALLOCATION_UTILS_H
#define LAB1LLP_SECTOR_ALLOCATION_UTILS_H

#include <stdint.h>
#include <stdio.h>

uint32_t allocate_sector(FILE* file, int alloc_size, uint32_t prev_sector, uint32_t next_sector);
void deallocate_sector(FILE* file, uint32_t sector_number);

#endif //LAB1LLP_SECTOR_ALLOCATION_UTILS_H
