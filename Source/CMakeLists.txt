
add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(Core)
target_link_libraries(${PROJECT_NAME} PRIVATE core_module)

add_subdirectory(Utils)
target_link_libraries(${PROJECT_NAME} PRIVATE utils_module)

add_subdirectory(Graphics)
target_link_libraries(${PROJECT_NAME} PRIVATE graphics_module)

add_subdirectory(Input)
target_link_libraries(${PROJECT_NAME} PRIVATE input_module)

add_subdirectory(Net)
target_link_libraries(${PROJECT_NAME} PRIVATE net_module)

add_subdirectory(Audio)
target_link_libraries(${PROJECT_NAME} PRIVATE audio_module)

# Specify include directories for the main executable
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Core
    ${CMAKE_CURRENT_SOURCE_DIR}/Utils
    ${CMAKE_CURRENT_SOURCE_DIR}/Graphics
    ${CMAKE_CURRENT_SOURCE_DIR}/Input
    ${CMAKE_CURRENT_SOURCE_DIR}/Net
    ${CMAKE_CURRENT_SOURCE_DIR}/Audio
)
