#include "core/_ModuleName0/ModuleName0.h"
#include "core/ModuleName1/ModuleName1.h"
#include "core/ModuleName2/ModuleName2.h"
#include "test/_ModuleName0/TestModuleName0.h"
#include "test/ModuleName1/TestModuleName1.h"
#include "test/ModuleName2/TestModuleName2.h"

#include <cstdlib>

int tmpMain() {
    int module_name_0_ret = testModuleName0();
    int module_name_1_ret = testModuleName1();
    int module_name_2_ret = testModuleName2();
	return EXIT_SUCCESS;
}
