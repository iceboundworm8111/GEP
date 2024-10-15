cmake_minimum_required(VERSION ${CMAKE_VERSION})

project(PROJECTENGINE)

 include_directories(
	 src
 )

add_library(ProjectEngine
src/ProjectEngine/ProjectEngine.h 
src/ProjectEngine/Core.cpp 
src/ProjectEngine/Core.h
src/ProjectEngine/Component.h
src/ProjectEngine/Component.cpp
src/ProjectEngine/Entity.cpp
src/ProjectEngine/Entity.h

)

add_executable(demo
	src/demo/main.cpp
	src/demo/Employee.cpp 	src/demo/Employee.h
)
target_link_libraries(demo ProjectEngine)