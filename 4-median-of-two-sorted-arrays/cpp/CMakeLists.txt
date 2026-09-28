cmake_minimum_required(VERSION 3.20)
project(median_of_two_sorted_arrays LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# findMedianSortedArrays.cpp is #included by solution.cpp; it is listed only so the IDE indexes it.
add_executable(median_of_two_sorted_arrays
    solution.cpp
    findMedianSortedArrays.cpp
)
set_source_files_properties(findMedianSortedArrays.cpp PROPERTIES HEADER_FILE_ONLY ON)
