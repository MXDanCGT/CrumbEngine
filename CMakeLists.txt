#Crumb Engine Root CMakeLists


cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Release>:Release>") #These lines come highly reccomended by LowLevelGameDev; 
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>") #/

project(CrumbEngine VERSION 0.01
					DESCRIPTION "An engine to really go *quackers* about")


add_subdirectory("engine") #Subdirectory containing engine code 

#By default, we dont want to build any of the applications, leave that to the application programmer... the curious can build the example applications they fancy
add_subdirectory("apps")
#TODO fork without apps? 

add_subdirectory("external/glad")
add_subdirectory("external/glfw")

target_link_libraries(CrumbEngine PRIVATE glfw glad) #atm, this is where we link... but is this good or should this be lower down?



#We export the engine here - TODO is this the best way to do this?
#Other option would be exporting in engine/CMakeLists.txt by each module individually... but that feels cumbersome
#export(TARGETS CrumbEngine NAMESPACE Crumb:: FILE "${CMAKE_BINARY_DIR}/CrumbEngine.cmake")