cmake_minimum_required(VERSION 3.25)
project(lab1llp C)

set(CMAKE_C_STANDARD 11)

file(GLOB_RECURSE consts_include_src "consts/*.h")
file(GLOB_RECURSE include_files_src "include/*.h")

file(GLOB_RECURSE debug_utils_src "debug/*.c")
file(GLOB_RECURSE instructions_src "instructions/*.c")
file(GLOB_RECURSE io_src "io/*.c")
file(GLOB_RECURSE operations_src "operations/*.c")
file(GLOB_RECURSE tests_src "tests/*.c")
file(GLOB_RECURSE utils_src "utils/*.c")

add_executable(lab1llp
        main.c
        ${consts_include_src}
        ${include_files_src}
        ${debug_utils_src}
        ${instructions_src}
        ${io_src}
        ${operations_src}
        ${tests_src}
        ${utils_src}
        )
