#apps CMakeLists.txt
#decides which application code we want to include...

cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)

set(CRUMB_APP "MorgCraft") #Set to morg craft for now..

#at the moment (dunno why this is all going in here but there we are)
# The application programmer's process
# 1 - Make a new folder in apps, using Base as a template if they fancy
# 2 - Change CRUMB_APP to their folder name
# 3 - code their own entry and they're away
#CHANGES AND THOUGHTS
# - Cache variable for CRUMB_APP so we can change from the command line / GUI 
# - Slightly increase abstraction of the process to the application programmer:
#				- Entry point in the engine, let the A.P. start with having to extend run NOT main...

if(${CRUMB_APP} STREQUAL "MorgCraft")
	add_subdirectory("MorgCraft")
else() #default app load - an empty app template
	add_subdirectory("Base")
endif()
