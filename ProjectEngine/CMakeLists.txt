cmake_minimum_required(VERSION ${CMAKE_VERSION})

project(PROJECTENGINE)

 include_directories(
	 src
	contrib/include
	contrib/cl-windows-x86_64/include

 )
link_directories(
${PROJECT_SOURCE_DIR}/contrib/cl-windows-x86_64/lib

)

add_library(Render
src/Render/Mesh.cpp
src/Render/Mesh.h
src/Render/Shader.cpp
src/Render/Shader.h
src/Render/Texture.h
src/Render/Texture.cpp
src/Render/Model.h
)

target_link_libraries(Render glew32 SDL2 opengl32)

add_library(ProjectEngine
src/ProjectEngine/ProjectEngine.h 
src/ProjectEngine/Core.h
src/ProjectEngine/Core.cpp 
src/ProjectEngine/Component.h
src/ProjectEngine/Component.cpp
src/ProjectEngine/Entity.cpp
src/ProjectEngine/Entity.h
src/ProjectEngine/Mesh.cpp
src/ProjectEngine/Mesh.h
src/ProjectEngine/Model.cpp
src/ProjectEngine/Model.h
src/ProjectEngine/Shader.cpp
src/ProjectEngine/Shader.h
src/ProjectEngine/Texture.cpp
src/ProjectEngine/Texture.h
src/ProjectEngine/RenderTexture.cpp
src/ProjectEngine/RenderTexture.h
src/ProjectEngine/RenderTexture.cpp
src/ProjectEngine/TriangleRenderer.h
src/ProjectEngine/TriangleRenderer.cpp
src/ProjectEngine/Window.h
src/ProjectEngine/Window.cpp


)
target_link_libraries(ProjectEngine Render)

add_executable(demo
	src/demo/main.cpp
	src/demo/Employee.cpp 	src/demo/Employee.h
)
target_link_libraries(demo ProjectEngine)