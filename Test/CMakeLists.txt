SET(EXE_NAME "Tests")

include_directories("${PROJECT_SOURCE_DIR}/Core/Include")
include_directories("${PROJECT_SOURCE_DIR}/Functional/Include")

add_executable(${EXE_NAME} Src/CppPracticeProjectTest.cpp)

target_link_libraries(${EXE_NAME})

set_property(TARGET ${EXE_NAME} PROPERTY FOLDER "Test")

install (TARGETS ${EXE_NAME}
         RUNTIME DESTINATION ${PROJECT_BINARY_DIR}/bin)