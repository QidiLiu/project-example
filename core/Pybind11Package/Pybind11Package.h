#ifndef PROJECTEXAMPLE_PYBIND11PACKAGE_H_
#define PROJECTEXAMPLE_PYBIND11PACKAGE_H_

#include <pybind11/pybind11.h>
#include "spdlog/spdlog.h"

namespace py = pybind11;

class Pybind11Package {

public:

    Pybind11Package();

    ~Pybind11Package();

};

#endif // PROJECTEXAMPLE_PYBIND11PACKAGE_H_
