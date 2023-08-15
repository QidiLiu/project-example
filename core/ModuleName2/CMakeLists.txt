set(MODULE_NAME ModuleName2)

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

set(ModuleName2_TEST_FLAG FALSE)

if(ModuleName2_TEST_FLAG)
    cmake_minimum_required(VERSION 3.24)

    set(TEST ModuleName2-test)
    project(${TEST} C CXX)

    set(CMAKE_C_STANDARD 11)
    set(CMAKE_CXX_STANDARD 20)

    if(NOT DEFINED spdlog_FOUND)
        find_package(spdlog REQUIRED)
    endif()

    include_directories(${ROOT_DIR})

    add_executable(${TEST})
        target_include_directories(${TEST} PUBLIC ${spdlog_INCLUDE_DIR})

        target_sources(${TEST} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/test.cc)
        add_dependencies(${TEST} ${MODULE_NAME})
        target_link_libraries(${TEST} ${MODULE_NAME})
endif()
