#include "core/PythonWrapper/PythonWrapper.h"
#include "core/ModuleName1/ModuleName1.h"

PYBIND11_MODULE(core, m) {
    m.doc() = "Interface of modules for Python. Developed by QidiLiu.";
    
    py::class_<ModuleName1>(m, "TestClass", py::dynamic_attr())
        .def(py::init<const std::string&>())
        .def_readwrite("dev_mode", &ModuleName1::dev_mode)
        .def_property("purpose", &ModuleName1::setPurpose, &ModuleName1::getPurpose)
        .def("setPurpose", &ModuleName1::setPurpose)
        .def("getPurpose", &ModuleName1::getPurpose);
}

