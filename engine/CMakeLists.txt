#engine CMakeLists
#Engine customisation / enabling / disabling modules
cmake_minimum_required(VERSION 4.2)
set(CMAKE_CXX_STANDARD 17)



file(GLOB_RECURSE CRUMB_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_library(CrumbEngine STATIC ${CRUMB_SOURCES})
target_include_directories(CrumbEngine PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/")
target_include_directories(CrumbEngine PUBLIC "${PROJECT_SOURCE_DIR}/external/glm")
target_include_directories(CrumbEngine PUBLIC "${PROJECT_SOURCE_DIR}/external/glad")
target_include_directories(CrumbEngine PUBLIC "${PROJECT_SOURCE_DIR}/external/glfw")
target_include_directories(CrumbEngine PUBLIC "${PROJECT_SOURCE_DIR}/external/stb")
#Add shaders to sources
target_sources(CrumbEngine PRIVATE ${SHADERS})

target_precompile_headers(CrumbEngine PRIVATE "include/pch.h")