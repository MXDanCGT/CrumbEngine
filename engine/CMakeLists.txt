#engine CMakeLists
#Engine customisation / enabling / disabling modules

cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)



add_subdirectory(core) #Core is required

add_library(CrumbEngine STATIC "CrumbEntry.cpp")
target_include_directories(CrumbEngine PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")