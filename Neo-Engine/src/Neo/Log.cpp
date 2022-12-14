#include "NeoPCH.h"
#include "Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"

namespace Neo {

    std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
    std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

    void Log::Init()
    {
         spdlog::set_pattern("%^[%T] %n: %v%$");
        //spdlog::set_pattern("[%H:%M:%S %z] [%n] [%^---%L---%$] [thread %t] %v");

        s_CoreLogger = spdlog::stdout_color_mt("Neo");
        s_CoreLogger->set_level(spdlog::level::trace);

        s_ClientLogger = spdlog::stdout_color_mt("APP");
        s_ClientLogger->set_level(spdlog::level::trace);
    }
}