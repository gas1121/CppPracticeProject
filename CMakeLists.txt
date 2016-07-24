cmake_minimum_required(VERSION 3.1)

project(CppPraticeProject)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

message("cxx Flags: " ${CMAKE_CXX_FLAGS})

add_subdirectory(Core)
add_subdirectory(Functional)
add_subdirectory(Test)
add_subdirectory(ThirdParty)