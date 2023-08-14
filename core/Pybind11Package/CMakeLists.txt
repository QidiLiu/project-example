set(MODULE_NAME Pybind11Package)

if(NOT DEFINED spdlog_FOUND)
    find_package(spdlog REQUIRED)
endif()

if(NOT DEFINED pybind11_FOUND)
    find_package(pybind11 REQUIRED)
endif()

file(
    GLOB_RECURSE SRC_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

add_library(${MODULE_NAME} ${SRC_FILES})
    target_include_directories(${MODULE_NAME} PUBLIC ${spdlog_INCLUDE_DIR})
    target_include_directories(${MODULE_NAME} PUBLIC ${pybind11_INCLUDE_DIR})
    target_include_directories(${MODULE_NAME} PUBLIC ${Python_INCLUDE_DIR})
    target_link_directories(${MODULE_NAME} PUBLIC ${Python_LIB_DIR})

    add_dependencies(${MAIN} ${MODULE_NAME})
    target_link_libraries(${MAIN} ${MODULE_NAME})
