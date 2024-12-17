cmake_minimum_required(VERSION ${CMAKE_VERSION})
project(GEPAL)

include_directories(
  contrib/cl-windows-amd64/include
)

link_directories(
  contrib/cl-windows-amd64/lib
)

add_executable(gepal
  src/main.cpp
)
target_link_libraries(gepal openal32)