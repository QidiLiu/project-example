# coding=utf-8

""" Implementation of Utilities """

__author__ = 'QidiLiu'

import configparser
import logging
from os import path as os_path
from os import makedirs as os_makedirs

DEBUG_terminateProgram_FLAG = False
DEBUG_terminateProgram_I = 0

DEBUG_readConfig_FLAG = False

class LogSecretary(logging.getLoggerClass()):

    # constructor and deconstructor

    def __init__(
            self,
            init_file_name,
            init_save_dir,
            init_thread_name='main',
            init_level=logging.INFO
    ):
        super().__init__(init_file_name, init_level)

        formatter = logging.Formatter(
            r'[{levelname}] {name} LINE-{lineno} {asctime} {message}',
            r'%Y-%m-%d %H:%M',
            '{'
        )

        console_handler = logging.StreamHandler()
        console_handler.setLevel(init_level)
        console_handler.setFormatter(formatter)
        self.addHandler(console_handler)

        if not os_path.exists(init_save_dir):
            os_makedirs(init_save_dir)

        file_handler = logging.FileHandler(
            f"{init_save_dir}/{init_thread_name}.log", encoding='utf-8'
        )

        file_handler.setFormatter(formatter)
        self.addHandler(file_handler)


def terminateProgram(in_functions) -> None:
    for stopFunc in in_functions:
        stopFunc()

def readConfig(in_path) -> dict:
    out_config = {}
    tmp_dict = {}
    config_parser = configparser.ConfigParser()
    config_parser.read(in_path)

    # Get all defaults

    config_defaults = config_parser.defaults()
    
    for key in config_defaults.keys():
        tmp_dict[key] = config_defaults[key]

    out_config['default'] = tmp_dict

    # Get sections and iterate over each

    config_sections = config_parser.sections()

    for config_section in config_sections:
        config_options = config_parser.options(config_section)
        tmp_dict = {}

        for config_option in config_options:
            tmp_dict[config_option] = config_parser.get(config_section, config_option)
        
        out_config[config_section] = tmp_dict
    
    return out_config

if __name__ == '__main__':
    pass

    if (DEBUG_terminateProgram_FLAG):
        def testFuncForTerminateProgram():
            global DEBUG_terminateProgram_I

            print(f"Test function no.{DEBUG_terminateProgram_I} is running...")
            DEBUG_terminateProgram_I += 1

        test_function_list = []
        test_function_num = 66

        for i in range(test_function_num):
            test_function_list.append(testFuncForTerminateProgram)

        terminateProgram(test_function_list)

    if (DEBUG_readConfig_FLAG):
        main_config_path = './meta/config/main.ini'
        config = readConfig(main_config_path)
        print(f"main_ui_path: {config['default']['main_ui_path']}")
