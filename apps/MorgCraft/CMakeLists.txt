#Example Project (MorgCraft) CMakeLists

cmake_minimum_required(VERSION 4.2)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE APP_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_executable(MorgCraft) 
target_sources(MorgCraft PRIVATE ${APP_SOURCES})
target_sources(MorgCraft PRIVATE ${SHADERS}) #Defined up a level, should be good 
target_include_directories(MorgCraft PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")

target_link_libraries(MorgCraft PRIVATE CrumbEngine)

