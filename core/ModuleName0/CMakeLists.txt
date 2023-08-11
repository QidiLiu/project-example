set(MODULE_NAME ModuleName0)

file(
    GLOB_RECURSE SRC_FILES
    "${ROOT_DIR}/core/${MODULE_NAME}/*.h"
    "${ROOT_DIR}/core/${MODULE_NAME}/*.cpp"
)

add_library(${MODULE_NAME} ${SRC_FILES})
