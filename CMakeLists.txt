cmake_minimum_required(VERSION 3.20)

project(point_cloud_viewer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

add_executable(point_cloud_viewer
    src/main.cpp
    include/shader.h
)

target_include_directories(point_cloud_viewer PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_definitions(point_cloud_viewer
    PRIVATE
        GL_SILENCE_DEPRECATION
)

target_link_libraries(point_cloud_viewer
    OpenGL::GL
    glfw
)
