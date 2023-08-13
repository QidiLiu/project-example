set(MODULE_NAME ModuleName2)

file(
    GLOB_RECURSE SRC_FILES
    "${CMAKE_SOURCE_DIR}/*.h"
    "${CMAKE_SOURCE_DIR}/*.cpp"
)

add_library(${MODULE_NAME} ${SRC_FILES})
add_dependencies(${MAIN} ${MODULE_NAME})
target_link_libraries(${MAIN} ${MODULE_NAME})

set(ModuleName2_TEST_FLAG FALSE)

if(ModuleName2_TEST_FLAG)
    cmake_minimum_required(VERSION 3.24)

    set(TEST ModuleName2-test)
    project(${TEST} C CXX)

    set(CMAKE_C_STANDARD 11)
    set(CMAKE_CXX_STANDARD 20)

    find_package(spdlog REQUIRED)
    include_directories(${spdlog_INCLUDE_DIR})

    include_directories(${ROOT_DIR})

    add_executable(${TEST})
        target_sources(${TEST} PRIVATE ${ROOT_DIR}/core/${MODULE_NAME}/test.cc)
        add_dependencies(${TEST} ${MODULE_NAME})
        target_link_libraries(${TEST} ${MODULE_NAME})
endif()
