#include "core/ModuleName1/ModuleName1.h"

ModuleName1::ModuleName1(const std::string& init_purpose) {
    this->dev_mode = true;
    this->purpose = init_purpose;

    const std::string module_name = "ModuleName1";
    auto console_sink = std::make_shared<spdlog::sinks::stderr_color_sink_mt>();

    auto file_sink = std::make_shared<spdlog::sinks::rotating_file_sink_mt>(
        "log/"+module_name+".log",
        1024 * 1024 * 10,
        3
    );

    spdlog::logger* raw_log_ptr = new spdlog::logger(module_name, { console_sink, file_sink });
    this->log_ptr = std::shared_ptr<spdlog::logger>(raw_log_ptr);

    this->log_ptr->info("ModuleName1 initialized.");
}

void ModuleName1::setPurpose(const std::string& in_purpose) {
    this->purpose = in_purpose;
}

const std::string ModuleName1::getPurpose() {
    return this->purpose;
}


