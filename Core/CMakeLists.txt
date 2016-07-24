SET(LIB_NAME Core)

set (SOURCES
     "Src/Dummy.cpp")
set (Include 
     "Include/Core/TypeTraits.hpp")

source_group("" FILES )
source_group("Include" FILES ${Include})

include_directories(.)

add_library(${LIB_NAME} STATIC ${SOURCES} ${Include})
set_target_properties(${LIB_NAME} PROPERTIES LINKER_LANGUAGE CXX)

set_property(TARGET ${LIB_NAME} PROPERTY FOLDER "BaseLibrary")