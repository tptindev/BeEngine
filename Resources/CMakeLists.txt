# Get a list of all subdirectories in the current directory
file(GLOB subdirectories LIST_DIRECTORIES true ${CMAKE_CURRENT_SOURCE_DIR}/*)

# Iterate through the list of subdirectories
foreach(subdirectory ${subdirectories})
    if(IS_DIRECTORY ${subdirectory})
        # copy game Resources into build/Resources directory
        file(COPY
            "${subdirectory}"
            DESTINATION ${CMAKE_BINARY_DIR}/Resources)
    endif()
endforeach()