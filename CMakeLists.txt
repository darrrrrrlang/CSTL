cmake_minimum_required (VERSION 2.8)

project (CSTL)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

aux_source_directory(. SRCS_ROOT)
aux_source_directory(./src SRCS_SUB)

add_executable(CSTL 
${SRCS_ROOT} 
${SRCS_SUB} 
)

if(UNIX)
	target_link_libraries(CSTL -lpthread)	
endif(UNIX)
