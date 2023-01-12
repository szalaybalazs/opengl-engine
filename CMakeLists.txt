cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(hyper VERSION 1.0)

add_definitions(-std=c++17)
set(CXX_FLAGS "-Wall" "-Werror" "-Wextra" "-fsanitize=undefined,address")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")
set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/dist/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/dist/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(
    hyper 
    src/cpp/Camera.cpp
    src/cpp/Display.cpp
    src/cpp/Framebuffer.cpp
    src/cpp/GLSLProgram.cpp
    src/cpp/Keyboard.cpp
    src/cpp/Light.cpp
    src/cpp/Mesh.cpp
    src/cpp/Model.cpp
    src/cpp/OBJLoader.cpp
    src/cpp/Program.cpp
    src/cpp/Scene.cpp
    src/cpp/Texture.cpp
    src/cpp/Window.cpp
    src/cpp/App.cpp
)

find_package(glfw3 3.4 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW 2.2 REQUIRED)

target_include_directories(hyper PUBLIC ${OPENGL_INCLUDE_DIR})
target_include_directories(hyper PUBLIC ${GLEW_INCLUDE_DIR})

target_include_directories(hyper PRIVATE
  include/
  lib/
)

target_link_libraries(hyper glfw ${OPENGL_gl_LIBRARY})
target_link_libraries(hyper GLEW::GLEW)

if (APPLE)
    target_link_libraries(hyper "-framework OpenGL")
endif (APPLE)

# clang++ 
# -g 
# -I ./include/ 
# -I /usr/local/include/ 
# -I ./lib/ 
# -framework OpenGL 
# -L ./lib/ 
# -lglew 
# -lglfw 
# ./src/cpp/*.cpp 
# -o opengl-app


