file(GLOB_RECURSE SOURCE_FILES "*.cpp" "*.h")

# Define the library in utils
add_library(ecs_module ${SOURCE_FILES})

# Include directories, if needed
target_include_directories(ecs_module PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/Systems
    ${CMAKE_CURRENT_SOURCE_DIR}/Entity
    ${CMAKE_CURRENT_SOURCE_DIR}/Component
)

target_link_libraries(ecs_module PRIVATE core_module utils_module)
