set(MODULE_NAME ModuleName2)

if(NOT DEFINED spdlog_FOUND)
    find_package(spdlog CONFIG REQUIRED)
endif()

file(GLOB_RECURSE SRC_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_library(${MODULE_NAME} ${SRC_FILES})
    target_link_libraries(${MODULE_NAME} PUBLIC spdlog::spdlog)

    target_link_libraries(${MAIN} PRIVATE ${MODULE_NAME})

set(ModuleName2_TEST_FLAG FALSE)

if(ModuleName2_TEST_FLAG)
    cmake_minimum_required(VERSION 3.24)

    set(TEST ModuleName2-test)
    project(${TEST} C CXX)

    set(CMAKE_C_STANDARD 11)
    set(CMAKE_CXX_STANDARD 20)

    if(NOT DEFINED spdlog_FOUND)
        find_package(spdlog CONFIG REQUIRED)
    endif()

    include_directories(${COMPONENT_DIR})

    add_executable(${TEST})
        target_link_libraries(${MAIN} PUBLIC spdlog::spdlog)

        target_sources(${TEST} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/test.cc)
        add_dependencies(${TEST} ${MODULE_NAME})
        target_link_libraries(${TEST} PRIVATE ${MODULE_NAME})
endif()
