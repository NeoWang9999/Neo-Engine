#pragma once

#include "Core.h"
#include"spdlog/spdlog.h"


namespace Neo {
    class NEO_API Log
    {
    public:
        static void Init();

        inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
        inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };
}


// Core log macros
#define NEO_CORE_TRACE(...)    ::Neo::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define NEO_CORE_INFO(...)     ::Neo::Log::GetCoreLogger()->info(__VA_ARGS__)
#define NEO_CORE_WARN(...)     ::Neo::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define NEO_CORE_ERROR(...)    ::Neo::Log::GetCoreLogger()->error(__VA_ARGS__)
#define NEO_CORE_FATAL(...)    ::Neo::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define NEO_TRACE(...)         ::Neo::Log::GetClientLogger()->trace(__VA_ARGS__)
#define NEO_INFO(...)          ::Neo::Log::GetClientLogger()->info(__VA_ARGS__)
#define NEO_WARN(...)          ::Neo::Log::GetClientLogger()->warn(__VA_ARGS__)
#define NEO_ERROR(...)         ::Neo::Log::GetClientLogger()->error(__VA_ARGS__)
#define NEO_FATAL(...)         ::Neo::Log::GetClientLogger()->fatal(__VA_ARGS__)
