cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Release>:Release>")
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

add_subdirectory("external/glfw") #GLFW - Window / Input management...

project(CrumbEngine VERSION 0.01)

file(GLOB_RECURSE CRUMB_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/Engine/*.cpp") #saves us adding the source files by hand


add_executable(CrumbEngine ${CRUMB_SOURCES}) #Engine Entry Executable
target_include_directories(CrumbEngine PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/Engine") #Including all the header files here...


target_link_libraries(CrumbEngine PRIVATE glfw)



project(MorgCraft VERSION 0.01)
add_executable(MorgCraft "src/MorgCraft/MCEntry.cpp") #Game Entry Executable ("MorgCraft" [TODO Change this fucking name])

