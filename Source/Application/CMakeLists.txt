file(GLOB_RECURSE SOURCE_FILES "*.cpp" "*.h")

# Define the library in utils
add_library(app_module ${SOURCE_FILES})

# Include directories, if needed
target_include_directories(app_module PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(app_module PRIVATE engine_module core_module input_module graphics_module utils_module)
