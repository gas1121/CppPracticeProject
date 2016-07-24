SET(LIB_NAME ThirdParty)

set (GLOB TEMP
     "*.cpp")

source_group("" FILES )
source_group("TEMP" FILES ${TEMP})

include_directories(.)

add_library(${LIB_NAME} STATIC ${TEMP})
set_target_properties(${LIB_NAME} PROPERTIES LINKER_LANGUAGE CXX)

set_property(TARGET ${LIB_NAME} PROPERTY FOLDER "ThirdParty")

#Problem with folder for project files.
#add_library(${LIB_NAME} INTERFACE)
#target_include_directories(${LIB_NAME} INTERFACE ...)

#add_custom_target(${LIB_NAME}_ide SOURCES ${SOURCES} ${FUNCTIONAL})
