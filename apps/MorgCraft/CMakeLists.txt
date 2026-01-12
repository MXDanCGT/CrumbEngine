#Example Project (MorgCraft) CMakeLists

cmake_minimum_required(VERSION 4.2)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE APP_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")


add_executable(MorgCraft) 
target_sources(MorgCraft PRIVATE ${APP_SOURCES})
target_include_directories(MorgCraft PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_include_directories(MorgCraft PUBLIC "${PROJECT_SOURCE_DIR}/external/ecs.hpp") #Have ecs available to our user??
target_link_libraries(MorgCraft PRIVATE CrumbEngine)

add_custom_target(ShaderResources ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${PROJECT_SOURCE_DIR}/engine/src/resources
            $<TARGET_FILE_DIR:MorgCraft>/resources
)


add_dependencies(MorgCraft ShaderResources)