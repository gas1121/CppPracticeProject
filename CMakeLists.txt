cmake_minimum_required(VERSION 2.8)

project(CppPracticeProject)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

message("cxx Flags: " ${CMAKE_CXX_FLAGS})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(CppPracticeProject)
