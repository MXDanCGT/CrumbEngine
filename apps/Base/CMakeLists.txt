#Base app CMakeLists.txt
#Remember to change the name of files when creating your own app :)

cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE APP_SOURCES CONFIGURE_DEPENDS "/src/*.cpp")


add_executable(YourCrumbApp)
target_sources(YourCrumbApp PRIVATE ${APP_SOURCES})
target_include_directories(YourCrumbApp PRIVATE "/include/")
