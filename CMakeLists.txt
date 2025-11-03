cmake_minimum_required(VERSION 3.16)


set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Release>:Release>")
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

project(CrumbEngine VERSION 0.01)
add_executable(CrumbEngine "src/Engine/CrumbEntry.cpp") #Engine Entry Executable


project(MorgCraft VERSION 0.01)
add_executable(MorgCraft "src/MorgCraft/MCEntry.cpp") #Game Entry ("MorgCraft" [TODO Change this fucking name])
