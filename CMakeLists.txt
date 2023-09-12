cmake_minimum_required(VERSION 3.25)
project(lab1llp C)

set(CMAKE_C_STANDARD 11)

add_executable(lab1llp
        main.c
        types/column_types.c include/types/column_types.h
        types/cell_types/int_cell.c include/types/cell_types/int_cell.h
        types/cell_types/cell.c include/types/cell_types/cell.h include/types/cell_types/string_cell.h include/types/cell_types/bool_cell.h include/types/cell_types/bigint_cell.h include/types/cell_types/float_cell.h include/types/schema/table_schema.h include/types/file_static_header.h io/files/file_manager.c consts/sector_consts.h include/sectors/sectors.h operations/files/create_static_header.c operations/files/create_static_header.h consts/table_consts.h operations/tables/table_schema_utils.c operations/tables/table_schema_utils.h)
