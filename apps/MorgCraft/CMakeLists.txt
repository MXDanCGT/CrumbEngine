#Example Project (MorgCraft) CMakeLists

cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE APP_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_executable(MorgCraft)
target_sources(MorgCraft PRIVATE ${APP_SOURCES})
target_include_directories(MorgCraft PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")
