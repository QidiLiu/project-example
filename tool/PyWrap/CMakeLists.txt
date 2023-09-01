if(NOT DEFINED pybind11_FOUND)
    set(PY_ID 39)
    set(PYBIND11_PYTHON_VERSION 3.9)
    set(pybind11_DIR "D:/Tool/python${PY_ID}/Lib/site-packages/pybind11/share/cmake/pybind11")
    set(PYTHON_EXECUTABLE "D:/Tool/python${PY_ID}/python.exe")
    find_package(pybind11 CONFIG REQUIRED)
endif()

file(
    GLOB_RECURSE SRC_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

pybind11_add_module(core ${SRC_FILES})
    add_custom_command(
        TARGET core POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_BINARY_DIR}/tool/PyWrap/core.cp${PY_ID}-win_amd64.pyd" "${ROOT_DIR}/out/pyd/core.pyd"
    )
