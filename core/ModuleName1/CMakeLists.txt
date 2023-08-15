set(MODULE_NAME ModuleName1)

if(NOT DEFINED spdlog_FOUND)
    find_package(spdlog REQUIRED)
endif()

file(
    GLOB_RECURSE SRC_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

add_library(${MODULE_NAME} ${SRC_FILES})
    target_include_directories(${MODULE_NAME} PUBLIC ${spdlog_INCLUDE_DIR})

    target_link_libraries(${MAIN} ${MODULE_NAME})
    target_link_libraries(core PRIVATE ${MODULE_NAME})
