cmake_minimum_required(VERSION 3.24)

set(VCPKG_ROOT D:/Tool/vcpkg)
set(CMAKE_TOOLCHAIN_FILE "${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
    CACHE STRING "Vcpkg toolchain file")
set(VCPKG_FEATURE_FLAGS "versions")

set(MAIN Cpp_Component)
project(${MAIN} C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 20)

find_package(spdlog CONFIG REQUIRED)

set(COMPONENT_ROOT ${CMAKE_CURRENT_SOURCE_DIR})
set(PROJECT_ROOT ${COMPONENT_ROOT}/../..)
include_directories(${COMPONENT_ROOT})

set(MODULE_TO_WRAP ModuleName1)
set(PY_PKG PYD_${MODULE_TO_WRAP})
add_subdirectory(${COMPONENT_ROOT}/tool/PyWrap)

add_executable(${MAIN})
    target_link_libraries(${MAIN} PUBLIC spdlog::spdlog)

    add_subdirectory(${COMPONENT_ROOT}/core/ModuleName0)
    add_subdirectory(${COMPONENT_ROOT}/core/ModuleName1)
    add_subdirectory(${COMPONENT_ROOT}/core/ModuleName2)
    target_sources(${MAIN} PRIVATE ${COMPONENT_ROOT}/core/main.cc)

