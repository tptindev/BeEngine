file(GLOB_RECURSE SOURCE_FILES "*.cpp" "*.h")

# Define the library in utils
add_library(graphics_module ${SOURCE_FILES})

# Include directories, if needed
target_include_directories(graphics_module PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(graphics_module PRIVATE core_module input_module utils_module engine_module SDL2 SDL2_image SDL2_ttf)
