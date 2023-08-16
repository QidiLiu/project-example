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
    add_custom_command(
        TARGET core POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy "${ROOT_DIR}/out/build/x64-Debug/core/PythonWrapper/core.cp311-win_amd64.pyd" "${ROOT_DIR}/out/pyd/core.pyd"
    )
