#include "Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"


namespace Praction {

	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	// Init customises the logger created by spdlog
	void Log::Init()
	{
		// spdlog pattern of formatting text
		spdlog::set_pattern("%^[%T] %n: %v%$");
		// %^ : color
		// %T : timestamp
		// %n : name of logger
		// %v%$ : log message

		// logger for game engine
		s_CoreLogger = spdlog::stdout_color_mt("Praction");
		s_CoreLogger->set_level(spdlog::level::trace);
		// set_level : set types of messages to be printed
		// trace : lowest level meaning all messages are printed

		// logger for client app
		s_ClientLogger = spdlog::stdout_color_mt("APP");
		s_ClientLogger->set_level(spdlog::level::trace);
	}

}
