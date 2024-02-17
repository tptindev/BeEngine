file(GLOB_RECURSE SOURCE_FILES "*.cpp" "*.h")

# Define the library in utils
add_library(engine_module ${SOURCE_FILES})

# Include directories, if needed
target_include_directories(engine_module PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(engine_module PRIVATE core_module utils_module graphics_module input_module)
