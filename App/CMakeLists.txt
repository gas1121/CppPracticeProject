include_directories("${PROJECT_SOURCE_DIR}/Core")

add_executable(app Src/main.cpp)

target_link_libraries(app)

set_property(TARGET app PROPERTY FOLDER "executables")

install (TARGETS app
         RUNTIME DESTINATION ${PROJECT_BINARY_DIR}/bin)