SET(EXE_NAME "TypeTraits")

set (SOURCES
     "Src/TypeTraitsMain.cpp")
set (Include 
     "Include/TypeTraits.hpp")

include_directories(./Include)
include_directories("${PROJECT_SOURCE_DIR}/ThirdParty/Include")

add_executable(${EXE_NAME} ${SOURCES} ${Include})

target_link_libraries(${EXE_NAME})

#set_property(TARGET ${EXE_NAME} PROPERTY FOLDER "TypeTraits")

install (TARGETS ${EXE_NAME}
         RUNTIME DESTINATION ${PROJECT_BINARY_DIR}/bin/TypeTraits)