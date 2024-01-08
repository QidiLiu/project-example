from sys import path
path.append('core/ModuleName1/PYD_ModuleName1')
from os import add_dll_directory
add_dll_directory("<path-to-bin-folder-for-DLLs>")
import PYD_ModuleName1

ModuleName1 = PYD_ModuleName1.ModuleName1