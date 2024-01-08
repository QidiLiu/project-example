set(MODULE_NAME ModuleName0)

if(NOT DEFINED spdlog_FOUND)
    find_package(spdlog CONFIG REQUIRED)
endif()

file(GLOB_RECURSE SRC_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_library(${MODULE_NAME} ${SRC_FILES})
    target_link_libraries(${MODULE_NAME} PUBLIC spdlog::spdlog)

    target_link_libraries(${MAIN} PRIVATE ${MODULE_NAME})
