file(GLOB_RECURSE SOURCE_FILES "*.cpp" "*.h")

# Define the library in utils
add_library(core_module ${SOURCE_FILES})

# Include directories, if needed
target_include_directories(core_module PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
