SET(LIB_NAME Functional)

set (SOURCES
     "Src/Dummy.cpp")
set (FUNCTIONAL 
     "Include/Delegates.hpp")

source_group("" FILES )
source_group("Include" FILES ${FUNCTIONAL})

include_directories(.)

add_library(${LIB_NAME} STATIC ${SOURCES} ${FUNCTIONAL})
set_target_properties(${LIB_NAME} PROPERTIES LINKER_LANGUAGE CXX)

set_property(TARGET ${LIB_NAME} PROPERTY FOLDER "BaseLibrary")

#Problem with folder for project files.
#add_library(${LIB_NAME} INTERFACE)
#target_include_directories(${LIB_NAME} INTERFACE ...)

#add_custom_target(${LIB_NAME}_ide SOURCES ${SOURCES} ${FUNCTIONAL})
