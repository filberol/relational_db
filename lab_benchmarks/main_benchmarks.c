#include <stdio.h>
#include <time.h>
#include "../include/tables/table_schema_utils.h"
#include "../include/instructions/file_instructions.h"
#include "../include/tables/table_cell_utils.h"
#include "../include/tables/table_row_utils.h"
#include <sys/stat.h>


const int MAX_ROWS = 1000;
const char* db_file_name = "bench.bin";


long get_file_size(const char* filename) {
    struct stat st;
    stat(filename, &st);
    return st.st_size;
}

int get_memory_usage() {
    FILE* file = fopen("/proc/self/status", "r");

    char buffer[1024] = "";
    int res;

    while (fscanf(file, " %1023s", buffer) == 1) {
        if (strcmp(buffer, "VmSize:") == 0) {
            fscanf(file, " %d", &res);
        }
    }
    fclose(file);

    return res;
}

int main() {
    FILE* result_set_file = fopen("../lab_bench_res/benchmark_results.csv", "w");
    FILE* database_file = fopen(db_file_name, "wb+");

    fprintf(result_set_file, "Rows,Insertion Time (ms),Deletion time(ms),File Size (bytes),Memory Usage (KB)\n");
    create_file_and_init_empty_structure(database_file);

    struct TableScheme table1scheme;
    init_table_scheme(database_file, "table1", 3, &table1scheme);
    schema_set_column(database_file, &table1scheme, 1, TABLE_TYPE_INT, "id");
    schema_set_column(database_file, &table1scheme, 2, TABLE_TYPE_BOOL, "value");
    schema_set_column(database_file, &table1scheme, 3, TABLE_TYPE_VARCHAR, "string");

    int id = 1;
    bool val = true;
    char* str = "test_string";
    union TableCellWithData table1row[table1scheme.columns_count];
    row_set_cell_value(database_file, &table1scheme, table1row, 1, TABLE_TYPE_INT, &id);
    row_set_cell_value(database_file, &table1scheme, table1row, 2, TABLE_TYPE_BOOL, &val);
    row_set_cell_value(database_file, &table1scheme, table1row, 3, TABLE_TYPE_VARCHAR, str);

    for (int row_num = 1; row_num <= MAX_ROWS; row_num++) {
        clock_t start, end;
        double insertion_time, deletion_time;
        long file_size;
        int memory_usage;

        file_size = get_file_size(db_file_name);
        memory_usage = get_memory_usage();

        start = clock();
        // Insert row into the table
        add_row_to_file(database_file, &table1scheme, table1row);
        end = clock();
        insertion_time = ((double) (end - start)) / CLOCKS_PER_SEC * 1000;

        start = clock();
        // Delete same row
        delete_row_from_file(database_file, row_num, &table1scheme);
        end = clock();
        deletion_time = ((double) (end - start)) / CLOCKS_PER_SEC * 1000;

        // Restore row
        add_row_to_file(database_file, &table1scheme, table1row);

        fprintf(result_set_file, "%d,%f,%f,%ld,%d\n", row_num, insertion_time, deletion_time, file_size, memory_usage);
    }

    fclose(result_set_file);

    return 0;
}

