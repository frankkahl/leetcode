cmake_minimum_required(VERSION 3.20)
project(maximum_nesting_depth_of_the_parentheses LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# maxDepth.cpp is #included by solution.cpp; it is listed only so the IDE indexes it.
add_executable(maximum_nesting_depth_of_the_parentheses
    solution.cpp
    maxDepth.cpp
)
set_source_files_properties(maxDepth.cpp PROPERTIES HEADER_FILE_ONLY ON)
