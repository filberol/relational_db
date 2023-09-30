#include "tests.h"

int check_sector_write() {
    // Create file
    struct StaticFileHeader def_header = create_file_header(10, 5, 1);
    FILE* file = fopen("test2.bin", "wb+");
    write_static_header(file, &def_header);

    // Allocate sector
    int sectors_needed = (sizeof(struct TableIndexArray) + sizeof(struct SectorHeader) + 100) / SECTOR_SIZE;
    uint32_t allocated_sector = allocate_sector(file, sectors_needed);
    printf("Allocated from sector %d\n", allocated_sector);

    // Create table index
    struct TableIndexArray def_table_index;
    def_table_index.table_map[0].table_name_hash = 123456;
    def_table_index.table_map[0].schema_sector = 12;

    // Write and check
    write_table_index_to_sector(file, allocated_sector, &def_table_index);
    struct TableIndexArray test_table_index;
    read_table_index_from_sector(file, allocated_sector, &test_table_index);

    printf("Test table hash %u\n", test_table_index.table_map[0].table_name_hash);

    return 0;
}