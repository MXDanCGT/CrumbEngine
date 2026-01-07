#Glad cmake lists file to allow us to simply "add_subdirectory"


cmake_minimum_required(VERSION 4.2)
project(glad)

add_library(glad)
target_sources(glad PRIVATE "src/glad.c")
target_include_directories(glad PUBLIC "include/")