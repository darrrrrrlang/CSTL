cmake_minimum_required (VERSION 2.8)

project (cstl)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

aux_source_directory(. SRCS_ROOT)
aux_source_directory(./src SRCS_SUB)

add_executable(${PROJECT_NAME}
${SRCS_ROOT} 
${SRCS_SUB} 
)

if(UNIX)
	target_link_libraries(${PROJECT_NAME} -lpthread)	
endif(UNIX)
