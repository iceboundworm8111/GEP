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
src/Render/Render.h
src/Render/Mesh.cpp
src/Render/Mesh.h
src/Render/Shader.cpp
src/Render/Shader.h
src/Render/Texture.h
src/Render/Texture.cpp
src/Render/Model.h

)

target_link_libraries(Render glew32 SDL2 opengl32 OpenAL32)

add_library(ProjectEngine
src/ProjectEngine/ProjectEngine.h 
src/ProjectEngine/Core.h
src/ProjectEngine/Core.cpp 
src/ProjectEngine/Component.h
src/ProjectEngine/Component.cpp
src/ProjectEngine/Entity.cpp
src/ProjectEngine/Entity.h
src/ProjectEngine/Window.h
src/ProjectEngine/Window.cpp
src/ProjectEngine/TriangleRenderer.cpp
src/ProjectEngine/TriangleRenderer.h
src/ProjectEngine/Keyboard.h
src/ProjectEngine/Keyboard.cpp
src/ProjectEngine/Mouse.h
src/ProjectEngine/Mouse.cpp
src/ProjectEngine/Transform.h
src/ProjectEngine/Transform.cpp
src/ProjectEngine/ModelRenderer.h
src/ProjectEngine/ModelRenderer.cpp
src/ProjectEngine/Resource.h
src/ProjectEngine/Resource.cpp
src/ProjectEngine/Resources.h
src/ProjectEngine/Resources.cpp
src/ProjectEngine/Model.h
src/ProjectEngine/Shader.h
src/ProjectEngine/Texture.h
src/ProjectEngine/Input.h
src/ProjectEngine/Input.cpp
src/ProjectEngine/Audio.h
src/ProjectEngine/Audio.cpp
src/ProjectEngine/AudioSource.h
src/ProjectEngine/AudioSource.cpp
src/ProjectEngine/Sound.h
src/ProjectEngine/Sound.cpp


)
target_link_libraries(ProjectEngine Render)

add_executable(demo
	src/demo/main.cpp
	src/demo/Employee.cpp 	src/demo/Employee.h
)
target_link_libraries(demo ProjectEngine)