#include "core/ModuleName1/ModuleName1.h"

ModuleName1::ModuleName1(const std::string& init_purpose) {
    dev_mode = true;
    purpose = init_purpose;

    const std::string module_name_ = "ModuleName1";
    auto console_sink_ = std::make_shared<spdlog::sinks::stderr_color_sink_mt>();

    auto file_sink_ = std::make_shared<spdlog::sinks::rotating_file_sink_mt>(
        "log/"+module_name_+".log",
        1024 * 1024 * 10,
        3
    );

    spdlog::logger* raw_log_ptr = new spdlog::logger(module_name_, { console_sink_, file_sink_ });
    log_ptr = std::shared_ptr<spdlog::logger>(raw_log_ptr);

    log_ptr->info("ModuleName1 initialized.");
}

void ModuleName1::setPurpose(const std::string& in_purpose) {
    purpose = in_purpose;
}

const std::string ModuleName1::getPurpose() {
    return purpose;
}


