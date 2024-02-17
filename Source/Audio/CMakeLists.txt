file(GLOB_RECURSE SOURCE_FILES "*.cpp" "*.h")

# Define the library in utils
add_library(audio_module ${SOURCE_FILES})

# Include directories, if needed
target_include_directories(audio_module PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(audio_module PRIVATE SDL2_mixer)
