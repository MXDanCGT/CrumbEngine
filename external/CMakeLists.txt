#Externals CMakeLists

cmake_minimum_required(VERSION 4.2)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(glfw) #Window and input
add_subdirectory(glm)
add_subdirectory(glad)
add_subdirectory(stb)
add_subdirectory(ecs.hpp)
add_subdirectory(miniaudio)