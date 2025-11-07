#Core submodule CMakeLists.txt
#creates the "core" submodule library

cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SOURCES_Core CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp") #Macro for grabbing source files rather than doing it by hand (ty LowLevelGameDev)

add_library(Core STATIC ${SOURCES_Core})
target_include_directories(Core PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/")


