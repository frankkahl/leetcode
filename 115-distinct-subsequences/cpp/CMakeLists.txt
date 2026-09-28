cmake_minimum_required(VERSION 3.20)
project(distinct_subsequences LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# numDistinct.cpp is #included by solution.cpp; it is listed only so the IDE indexes it.
add_executable(distinct_subsequences
    solution.cpp
    numDistinct.cpp
)
set_source_files_properties(numDistinct.cpp PROPERTIES HEADER_FILE_ONLY ON)
