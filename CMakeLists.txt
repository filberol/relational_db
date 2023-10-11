cmake_minimum_required(VERSION 3.25)
project(lab1llp C)

set(CMAKE_C_STANDARD 11)

file(GLOB_RECURSE consts_include_src "consts/*.h")
file(GLOB_RECURSE include_files_src "include/*.h")

file(GLOB_RECURSE debug_utils_src "debug/*.c")
file(GLOB_RECURSE instructions_src "instructions/*.c")
file(GLOB_RECURSE io_src "io/*.c")
file(GLOB_RECURSE operations_src "operations/*.c")
file(GLOB_RECURSE utils_src "utils/*.c")

file(GLOB_RECURSE tests_src "lab_tests/*.c")

add_library(lab1llp_lib
        ${consts_include_src}
        ${include_files_src}
        ${debug_utils_src}
        ${instructions_src}
        ${io_src}
        ${operations_src}
        ${utils_src}
    )

add_executable(lab1llp_tests
        lab_tests/main_tests.c
        ${tests_src}
    )

add_executable(lab1llp_benchmarks
        lab_benchmarks/main_benchmarks.c
        )

target_link_libraries(lab1llp_tests
        PRIVATE lab1llp_lib
    )

target_link_libraries(lab1llp_benchmarks
        PRIVATE lab1llp_lib
        )
