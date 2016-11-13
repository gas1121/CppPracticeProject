SET(EXE_NAME "CppPracticeProject")

set (SOURCES
     "Src/main.cpp")
set (Include 
     "Include/TypeTraits.hpp"
     "Include/TMPList.hpp")

include_directories(./Include)
include_directories("${PROJECT_SOURCE_DIR}/ThirdParty/Include")

add_executable(${EXE_NAME} ${SOURCES} ${Include})

target_link_libraries(${EXE_NAME})