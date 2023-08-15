#include "core/Pybind11Package/Pybind11Package.h"

#include "core/Pybind11Package/Pybind11Package.h"

Pybind11Package::Pybind11Package(const std::string& init_purpose) {
    dev_mode = true;
    purpose = init_purpose;

    const std::string logger_name_ = "Pybind11Package";
    auto console_sink_ = std::make_shared<spdlog::sinks::stderr_color_sink_mt>();
    auto file_sink_ = std::make_shared<spdlog::sinks::rotating_file_sink_mt>("log/"+logger_name_+".log", 1024 * 1024 * 10, 3);
    spdlog::logger* raw_log_ptr = new spdlog::logger(logger_name_, { console_sink_, file_sink_ });
    log_ptr = std::shared_ptr<spdlog::logger>(raw_log_ptr);

    log_ptr->info("Pybind11Package initialized.");
}

void Pybind11Package::setPurpose(const std::string& in_purpose) {
    purpose = in_purpose;
}

const std::string Pybind11Package::getPurpose() {
    return purpose;
}

PYBIND11_MODULE(core, m) {
    m.doc() = "Some purpose of this module. Developed by QidiLiu.";
    
    py::class_<Pybind11Package>(m, "Pybind11Package", py::dynamic_attr())
        .def(py::init<const std::string&>())
        .def_readwrite("dev_mode", &Pybind11Package::dev_mode)
        .def_property("purpose", &Pybind11Package::setPurpose, &Pybind11Package::getPurpose)
        .def("setPurpose", &Pybind11Package::setPurpose)
        .def("getPurpose", &Pybind11Package::getPurpose);
}

