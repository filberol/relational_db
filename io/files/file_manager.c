#include "../../include/files/file_manager.h"

FILE* open_file(const char* filename, const char* mode) {
    FILE* file_ptr;
    file_ptr = fopen(filename, mode);

    if (file_ptr == NULL) {
        perror("Error opening file");
        return NULL;
    }

    return file_ptr;
}

void close_file(FILE* file) {
    if (file != NULL) {
        if (fclose(file) == EOF) {
            perror("Error closing file");
        }
    }
}
