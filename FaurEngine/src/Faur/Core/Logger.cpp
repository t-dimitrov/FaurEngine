#include "Logger.h"

#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

namespace Faur
{
    std::shared_ptr<spdlog::logger> Logger::s_EngineLogger = nullptr;
    std::shared_ptr<spdlog::logger> Logger::s_AppLogger = nullptr;

    void Logger::Init()
    {
        // Engine -> [13:48:04][thread 13308][FAUR]
        std::vector<spdlog::sink_ptr> engineSinks = {
            std::make_shared<spdlog::sinks::stdout_color_sink_mt>(),
            std::make_shared<spdlog::sinks::basic_file_sink_mt>("Logs/Faur.log", true)
        };
        engineSinks[0]->set_pattern("%^[%T][thread %t][%n]: %v%$");
        engineSinks[1]->set_pattern("[%T][thread %t][%l] [%n]: %v");

        s_EngineLogger = std::make_shared<spdlog::logger>("FAUR", engineSinks.begin(), engineSinks.end());
        s_EngineLogger->set_level(spdlog::level::trace);

        // App -> [13:48:04][thread 13308][APP]
        std::vector<spdlog::sink_ptr> appSinks = {
            std::make_shared<spdlog::sinks::stdout_color_sink_mt>(),
            std::make_shared<spdlog::sinks::basic_file_sink_mt>("Logs/App.log", true)
        };
        appSinks[0]->set_pattern("%^[%T][thread %t][%n]: %v%$");
        appSinks[1]->set_pattern("[%T][thread %t][%l] [%n]: %v");

        s_AppLogger = std::make_shared<spdlog::logger>("APP", appSinks.begin(), appSinks.end());
        s_AppLogger->set_level(spdlog::level::trace);
    }

    void Logger::Shutdown()
    {
        s_EngineLogger.reset();
        s_AppLogger.reset();
        spdlog::drop_all();
    }

    std::shared_ptr<spdlog::logger>& Logger::EngineLoggerInstance()
    {
        return s_EngineLogger;
    }

    std::shared_ptr<spdlog::logger>& Logger::AppLoggerInstance()
    {
        return s_AppLogger;
    }
}
