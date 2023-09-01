cmake_minimum_required(VERSION 3.24)

set(MAIN project-example)
project(${MAIN} C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 20)

find_package(spdlog REQUIRED)

set(ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${ROOT_DIR})

add_subdirectory(${ROOT_DIR}/tool/PyWrap)

add_executable(${MAIN})
    target_include_directories(${MAIN} PUBLIC ${spdlog_INCLUDE_DIR})

    add_subdirectory(${ROOT_DIR}/core/ModuleName0)
    add_subdirectory(${ROOT_DIR}/core/ModuleName1)
    add_subdirectory(${ROOT_DIR}/core/ModuleName2)
    target_sources(${MAIN} PRIVATE ${ROOT_DIR}/core/main.cc)

