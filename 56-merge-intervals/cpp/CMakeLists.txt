cmake_minimum_required(VERSION 3.20)
project(merge_intervals LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# merge.cpp is #included by solution.cpp; it is listed only so the IDE indexes it.
add_executable(merge_intervals
    solution.cpp
    merge.cpp
)
set_source_files_properties(merge.cpp PROPERTIES HEADER_FILE_ONLY ON)
