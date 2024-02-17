file(GLOB_RECURSE SOURCE_FILES "*.cpp" "*.h")

# Define the library in utils
add_library(scenegraph_module ${SOURCE_FILES})

# Include directories, if needed
target_include_directories(scenegraph_module PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
