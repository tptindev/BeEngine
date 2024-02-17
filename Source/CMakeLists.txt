
add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(Core)
add_subdirectory(ECS)
add_subdirectory(Utils)
add_subdirectory(Graphics)
add_subdirectory(Input)
add_subdirectory(Net)
add_subdirectory(Audio)
add_subdirectory(Physics)
add_subdirectory(Engine)
add_subdirectory(SceneGraph)

target_link_libraries(${PROJECT_NAME} PRIVATE
    core_module
    engine_module
    scenegraph_module
    ecs_module
    utils_module
    graphics_module
    input_module
    net_module
    audio_module
)

# Specify include directories for the main executable
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Core
    ${CMAKE_CURRENT_SOURCE_DIR}/Utils
    ${CMAKE_CURRENT_SOURCE_DIR}/Graphics
    ${CMAKE_CURRENT_SOURCE_DIR}/Input
    ${CMAKE_CURRENT_SOURCE_DIR}/Net
    ${CMAKE_CURRENT_SOURCE_DIR}/Audio
    ${CMAKE_CURRENT_SOURCE_DIR}/ECS
    ${CMAKE_CURRENT_SOURCE_DIR}/SceneGraph
)
