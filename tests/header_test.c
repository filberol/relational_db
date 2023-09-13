#include <stdio.h>
#include "../include/types/file_static_header.h"
#include "../include/utils/static_header_utils.h"


int main() {
    // Create a new header
    struct StaticFileHeader def_header = create_file_header(10, 5);

    // Open the file for writing
    FILE* outFile = fopen("test.bin", "wb");

    if (outFile != NULL) {
        int writeResult = write_static_header(outFile, &def_header);

        if (writeResult == 0) {
            printf("Header successfully written to the beginning of the file.\n");
        } else {
            printf("Error writing header to the beginning of the file.\n");
        }

        fclose(outFile);
    } else {
        printf("Error opening file for writing.\n");
    }

    // Open the file for reading
    FILE* inFile = fopen("test.bin", "rb"); // Open the file for binary reading

    if (inFile != NULL) {
        struct StaticFileHeader read_header;
        int readResult = read_static_header(inFile, &read_header);

        if (readResult == 0) {
            printf("Header read from the beginning of the file:\n");
            printf("Table Count: %d\n", read_header.table_count);
            printf("Sector Table Count: %d\n", read_header.table_indices_sector);
        } else {
            printf("Error reading header from the beginning of the file.\n");
        }

        fclose(inFile);
    } else {
        printf("Error opening file for reading.\n");
    }

    return 0;
}
