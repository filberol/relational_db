#ifndef LAB1LLP_DEBUG_UTILS_H
#define LAB1LLP_DEBUG_UTILS_H

#include <stdio.h>
#include <stdint.h>

void debug_static_header(FILE* file);
void debug_table_indices_from_sector(FILE* file, uint32_t sector);

#endif //LAB1LLP_DEBUG_UTILS_H
