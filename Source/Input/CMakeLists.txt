file(GLOB_RECURSE SOURCE_FILES "*.cpp" "*.h")

# Define the library in utils
add_library(input_module ${SOURCE_FILES})

# Include directories, if needed
target_include_directories(input_module PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(input_module PRIVATE utils_module SDL2)
