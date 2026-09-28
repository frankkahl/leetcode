cmake_minimum_required(VERSION 3.20)
project(longest_substring_without_repeating_characters LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# lengthOfLongestSubstring.cpp is #included by solution.cpp; it is listed only so the IDE indexes it.
add_executable(longest_substring_without_repeating_characters
    solution.cpp
    lengthOfLongestSubstring.cpp
)
set_source_files_properties(lengthOfLongestSubstring.cpp PROPERTIES HEADER_FILE_ONLY ON)
