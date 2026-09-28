cmake_minimum_required(VERSION 3.20)
project(lfu_cache LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# LFUCache.cpp is #included by solution.cpp; it is listed only so the IDE indexes it.
add_executable(lfu_cache
    solution.cpp
    LFUCache.cpp
)
set_source_files_properties(LFUCache.cpp PROPERTIES HEADER_FILE_ONLY ON)
