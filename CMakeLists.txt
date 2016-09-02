cmake_minimum_required(VERSION 2.8)

project(CppPraticeProject)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

message("cxx Flags: " ${CMAKE_CXX_FLAGS})

add_subdirectory(Core)
add_subdirectory(Functional)
add_subdirectory(TypeTraits)
add_subdirectory(ThirdParty)
