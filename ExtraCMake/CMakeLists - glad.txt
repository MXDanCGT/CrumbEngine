#Glad cmake lists file to allow us to simply "add_subdirectory"


cmake_minimum_required(VERSION 4.2)
project(glad)

file(GLOB_RECURSE CRUMB_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/")

add_library(glad)
target_sources(glad PRIVATE "src/glad.c")
target_include_directories(glad PUBLIC "include/")