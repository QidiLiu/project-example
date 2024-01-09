if(NOT DEFINED pybind11_FOUND)
    set(PY_ID 312)
    set(PYBIND11_PYTHON_VERSION 3.12)
    set(Python_VIRTUALENV FIRST)
    set(PY_VENV ${PROJECT_ROOT}/component/python-component/.venv)
    set(pybind11_DIR "${PY_VENV}/Lib/site-packages/pybind11/share/cmake/pybind11")
    set(PYTHON_EXECUTABLE "${PY_VENV}/Scripts/python.exe")
    find_package(Python COMPONENTS Interpreter Development)
    find_package(pybind11 CONFIG REQUIRED)
endif()

file(GLOB_RECURSE SRC_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

pybind11_add_module(${PY_PKG} ${SRC_FILES})
    add_custom_command(
        TARGET ${PY_PKG} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_BINARY_DIR}/tool/PyWrap/${PY_PKG}.cp${PY_ID}-win_amd64.pyd" "${PROJECT_ROOT}/component/python-component/core/${MODULE_TO_WRAP}/${PY_PKG}/${PY_PKG}.pyd"
    )
