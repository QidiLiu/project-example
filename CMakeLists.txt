cmake_minimum_required(VERSION 3.24)

set(MAIN project-example)
project(${MAIN} C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 20)

find_package(spdlog REQUIRED)
include_directories(${spdlog_INCLUDE_DIR})

set(ROOT_DIR ${CMAKE_SOURCE_DIR})
include_directories(${ROOT_DIR})

add_executable(${MAIN})
    add_subdirectory(./core/ModuleName0)
    add_subdirectory(./core/ModuleName1)
    add_subdirectory(./core/ModuleName2)

    target_sources(${MAIN} PRIVATE ${ROOT_DIR}/core/main.cc)
