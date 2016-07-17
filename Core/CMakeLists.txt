SET(LIB_NAME Core)

set (SOURCES
     "Src/dummy.cpp")
set (FUNCTIONAL 
     "Include/Core/Functional/Delegates.hpp")

source_group("" FILES )
source_group("Functional" FILES ${FUNCTIONAL})

include_directories(.)

add_library(${LIB_NAME} STATIC ${SOURCES} ${FUNCTIONAL})
set_target_properties(${LIB_NAME} PROPERTIES LINKER_LANGUAGE CXX)

set_property(TARGET ${LIB_NAME} PROPERTY FOLDER "BaseLibrary")