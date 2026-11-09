cmake_minimum_required(VERSION 3.20)
project(maximal_rectangle LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# maximalRectangle.cpp is #included by solution.cpp; it is listed only so the IDE indexes it.
add_executable(maximal_rectangle
    solution.cpp
    maximalRectangle.cpp
)
set_source_files_properties(maximalRectangle.cpp PROPERTIES HEADER_FILE_ONLY ON)
