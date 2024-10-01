cmake_minimum_required(VERSION ${CMAKE_VERSION})

project(PROJECTENGINE)

 include_directories(
	 src
 )

add_library(ProjectEngine
src/ProjectEngine/Core.cpp src/ProjectEngine/Core.h
)

add_executable(demo
	src/demo/main.cpp
	src/demo/Employee.cpp 	src/demo/Employee.h
)
target_link_libraries(demo ProjectEngine)