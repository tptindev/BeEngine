set(CMAKE_VERBOSE_MAKEFILE ON)
cmake_minimum_required(VERSION 3.27.6)
project(BeEnggine VERSION 0.1.0 DESCRIPTION "Game engine from BeStudio" LANGUAGES C CXX)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
# specify the ouput directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

#
set(LIBRARY_DIR 
"${CMAKE_SOURCE_DIR}/3rd/libs/GLFW" 
"${CMAKE_SOURCE_DIR}/3rd/libs/SDL2")
set(INCLUDE_DIR 
"${CMAKE_SOURCE_DIR}/3rd/include/GLFW" 
"${CMAKE_SOURCE_DIR}/3rd/include/SDL2")

set(LINKER_LIBRARY "-lmingw32 -lSDL2main")

message("Root source directory: ${CMAKE_SOURCE_DIR}")
message("Output directory: ${CMAKE_BINARY_DIR}")

# Get a list of all subdirectories in the 3rd/bin directory
file(GLOB subdirectories LIST_DIRECTORIES true ${CMAKE_SOURCE_DIR}/3rd/bin/*)

# Iterate through the list of subdirectories
foreach(subdirectory ${subdirectories})
    if(IS_DIRECTORY ${subdirectory})
        # copy game bin into build/3rd/bin directory
        file(COPY
            "${subdirectory}"
            DESTINATION ${CMAKE_BINARY_DIR}/bin)
    endif()
endforeach()

include_directories(${INCLUDE_DIR})
link_directories(${LIBRARY_DIR})

add_subdirectory(Source)
add_subdirectory(Resources)


target_link_libraries(${PROJECT_NAME} PRIVATE ${LINKER_LIBRARY})
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)