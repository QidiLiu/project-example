#include "core/ModuleName0/ModuleName0.h"
#include "core/ModuleName1/ModuleName1.h"
#include "core/ModuleName2/ModuleName2.h"
#include "core/Pybind11Package/Pybind11Package.h"

#include <cstdlib>

#include "spdlog/spdlog.h"

int main() {
    spdlog::info("Program started.");
    ModuleName0 _module_name_0;
    ModuleName1 _module_name_1;
    ModuleName2 _module_name_2;
    Pybind11Package _pybind11_package;
    spdlog::info("Program ended.");

	return EXIT_SUCCESS;
}
