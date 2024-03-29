#include <cstdlib>

#include "spdlog/spdlog.h"

#include "core/ModuleName0/ModuleName0.h"
#include "core/ModuleName1/ModuleName1.h"
#include "core/ModuleName2/ModuleName2.h"

int main() {
    spdlog::info("Program started.");
    ModuleName0 module_name_0;
    ModuleName1 module_name_1("passing the butter");
    ModuleName2 module_name_2;
    spdlog::info("Program ended.");

    return EXIT_SUCCESS;
}
