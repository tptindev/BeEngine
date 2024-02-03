file(GLOB_RECURSE SOURCE_FILES "*.cpp" "*.h")

# Define the library in utils
add_library(core_module ${SOURCE_FILES}
    DataStruct/CSinglyLinkedList.h DataStruct/CSinglyLinkedList.cpp
    DataStruct/CDoublyLinkedList.h DataStruct/CDoublyLinkedList.cpp
    DataStruct/SNode.h)

# Include directories, if needed
target_include_directories(core_module PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/Memory
)

target_link_libraries(core_module PRIVATE utils_module)
