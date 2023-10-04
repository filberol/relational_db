#ifndef LAB1LLP_TESTS_H
#define LAB1LLP_TESTS_H

#include <stdio.h>
#include "../include/debug/debug_utils.h"
#include "../include/types/static/file_static_header.h"
#include "../include/utils/static_header_utils.h"
#include "../include/types/index/table_index.h"
#include "../include/sectors/sector_utils.h"
#include "../include/tables/table_index_utils.h"
#include "../include/instructions/file_instructions.h"
#include "../include/tables/table_schema_utils.h"
#include "../include/types/schema/column_types.h"
#include "../include/utils/file_string_utils.h"
#include "../include/tables/table_row_utils.h"

int test_header();
int test_alloc();
int check_sector_write();
int check_table_indices_update();
int check_write_data();
int init_and_debug_table();
int fill_rows();

#endif //LAB1LLP_TESTS_H
