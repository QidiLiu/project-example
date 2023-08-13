set(MODULE_NAME ModuleName1)

file(
    GLOB_RECURSE SRC_FILES
    "${CMAKE_SOURCE_DIR}/*.h"
    "${CMAKE_SOURCE_DIR}/*.cpp"
)

add_library(${MODULE_NAME} ${SRC_FILES})
add_dependencies(${MAIN} ${MODULE_NAME})
target_link_libraries(${MAIN} ${MODULE_NAME})
