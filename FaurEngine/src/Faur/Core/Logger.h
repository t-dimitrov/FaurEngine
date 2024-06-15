#pragma once
#include <spdlog/spdlog.h>

namespace Faur
{
    class Logger
    {
    public:
        static void Init();
        static void Shutdown();

        static std::shared_ptr<spdlog::logger>& EngineLoggerInstance();
        static std::shared_ptr<spdlog::logger>& AppLoggerInstance();

    private:
        static std::shared_ptr<spdlog::logger> s_EngineLogger;
        static std::shared_ptr<spdlog::logger> s_AppLogger;
    };

#ifdef FAUR_DEBUG
    // Engine logging macros
    #define FAUR_CORE_TRACE(...)    ::Faur::Logger::EngineLoggerInstance()->trace(__VA_ARGS__)
    #define FAUR_CORE_INFO(...)     ::Faur::Logger::EngineLoggerInstance()->info(__VA_ARGS__)
    #define FAUR_CORE_WARN(...)     ::Faur::Logger::EngineLoggerInstance()->warn(__VA_ARGS__)
    #define FAUR_CORE_ERROR(...)    ::Faur::Logger::EngineLoggerInstance()->error(__VA_ARGS__)
    #define FAUR_CORE_CRITICAL(...) ::Faur::Logger::EngineLoggerInstance()->critical(__VA_ARGS__)

    // App logging macros
    #define FAUR_TRACE(...)      ::Faur::Logger::AppLoggerInstance()->trace(__VA_ARGS__)
    #define FAUR_INFO(...)       ::Faur::Logger::AppLoggerInstance()->info(__VA_ARGS__)
    #define FAUR_WARN(...)       ::Faur::Logger::AppLoggerInstance()->warn(__VA_ARGS__)
    #define FAUR_ERROR(...)      ::Faur::Logger::AppLoggerInstance()->error(__VA_ARGS__)
    #define FAUR_CRITICAL(...)   ::Faur::Logger::AppLoggerInstance()->critical(__VA_ARGS__)
#else
    // Engine logging macros
    #define FAUR_CORE_TRACE(...)
    #define FAUR_CORE_INFO(...)
    #define FAUR_CORE_WARN(...)
    #define FAUR_CORE_ERROR(...)
    #define FAUR_CORE_CRITICAL(...)

    // App logging macros
    #define FAUR_TRACE(...)
    #define FAUR_INFO(...)
    #define FAUR_WARN(...)
    #define FAUR_ERROR(...)
    #define FAUR_CRITICAL(...)
#endif
}
