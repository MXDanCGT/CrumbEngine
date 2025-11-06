#Root CMakeLists for the whole thing

cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Release>:Release>") #These lines come highly reccomended by LowLevelGameDev; 
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>") #/

project(CrumbEngine VERSION 0.01)

add_subdirectory("engine") #Engine code
add_subdirectory("apps") #games running on Crumb

