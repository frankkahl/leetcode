cmake_minimum_required(VERSION 3.20)
project(two_sum LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# twoSum.cpp is #included by solution.cpp; it is listed only so the IDE indexes it.
add_executable(two_sum
    solution.cpp
    twoSum.cpp
)
set_source_files_properties(twoSum.cpp PROPERTIES HEADER_FILE_ONLY ON)
