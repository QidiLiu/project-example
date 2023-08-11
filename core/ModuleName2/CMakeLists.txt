set(MODULE_NAME ModuleName2)

file(
    GLOB_RECURSE SRC_FILES
    "${ROOT_DIR}/core/${MODULE_NAME}/*.h"
    "${ROOT_DIR}/core/${MODULE_NAME}/*.cpp"
)

add_library(${MODULE_NAME} ${SRC_FILES})

# test ModuleName2 independently

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

        target_link_libraries(
            ${TEST}
            ${MODULE_NAME}
        )

endif()
