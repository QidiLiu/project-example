#ifndef PROJECTEXAMPLE_MODULENAME1_H_
#define PROJECTEXAMPLE_MODULENAME1_H_

#include <string>

#include "spdlog/logger.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/rotating_file_sink.h"

class ModuleName1 {

public:

    bool dev_mode;

    ModuleName1(const std::string& init_purpose_);

    void setPurpose(const std::string& in_purpose_);

    const std::string getPurpose();

private:

    std::string purpose;
    std::shared_ptr<spdlog::logger> log_ptr;
};

#endif // PROJECTEXAMPLE_MODULENAME2_H_
