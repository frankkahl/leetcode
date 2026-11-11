cmake_minimum_required(VERSION 3.20)
project(find_duplicate_file_in_system LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# findDuplicate.cpp is #included by solution.cpp; it is listed only so the IDE indexes it.
add_executable(find_duplicate_file_in_system
    solution.cpp
    findDuplicate.cpp
)
set_source_files_properties(findDuplicate.cpp PROPERTIES HEADER_FILE_ONLY ON)
