set(MODULE_NAME Pybind11Package)

if(NOT DEFINED spdlog_FOUND)
    find_package(spdlog REQUIRED)
endif()

if(NOT DEFINED pybind11_FOUND)
    set(PYBIND11_PYTHON_VERSION 3.11)
    set(PYTHON_EXECUTABLE "C:/Tool/anaconda/envs/test/python.exe")
    find_package(pybind11 CONFIG REQUIRED)
endif()

file(
    GLOB_RECURSE SRC_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

pybind11_add_module(core ${SRC_FILES})
    target_include_directories(core PUBLIC ${spdlog_INCLUDE_DIR})
