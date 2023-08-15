#ifndef PROJECTEXAMPLE_PYBIND11PACKAGE_H_
#define PROJECTEXAMPLE_PYBIND11PACKAGE_H_

#include <string>

#include <pybind11/pybind11.h>
#include "spdlog/logger.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/rotating_file_sink.h"

namespace py = pybind11;

class Pybind11Package {

public:

    bool dev_mode;

    Pybind11Package(const std::string& init_purpose);

    void setPurpose(const std::string& in_purpose);

    const std::string getPurpose();

private:

    std::string purpose;
    std::shared_ptr<spdlog::logger> log_ptr;
};

#endif // PROJECTEXAMPLE_PYBIND11PACKAGE_H_
