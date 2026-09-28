cmake_minimum_required(VERSION 3.20)
project(lru_cache LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# LRUCache.cpp is #included by solution.cpp; it is listed only so the IDE indexes it.
add_executable(lru_cache
    solution.cpp
    LRUCache.cpp
)
set_source_files_properties(LRUCache.cpp PROPERTIES HEADER_FILE_ONLY ON)
