cmake_minimum_required(VERSION 3.21)
set(CMAKE_CXX_STANDARD 20) # min c++ standart is c++17

project(DiplomaEngine)

find_package(OpenGL REQUIRED)
find_package(glfw3 3.3 REQUIRED)

set(CORE
Engine/Engine.cpp
Engine/Window/WindowsManager.cpp
Engine/Point/Point.cpp
Engine/Line/Line.cpp
Engine/Bezier/Bezier.cpp
Engine/BSpline/BSpline.cpp
Engine/Shader/Shader.cpp
Engine/Render/Render.cpp)

add_executable(DiplomaEngine main.cpp glad.c ${CORE})
target_link_libraries(DiplomaEngine glfw OpenGL::GL)

# command to update resources every build
add_custom_command(
        TARGET DiplomaEngine PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
                ${CMAKE_SOURCE_DIR}/Resources
                ${CMAKE_CURRENT_BINARY_DIR}/Resources)