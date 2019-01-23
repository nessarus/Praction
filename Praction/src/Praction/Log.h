#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Praction {
	class PRACTION_API Log
	{
	public:
		// Init customises the logger created by spdlog 
		static void Init();

		// functions to return game engine's or client logger 
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		// smart pointers to the game engine's or client logger
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define PT_CORE_TRACE(...)	::Praction::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define PT_CORE_INFO(...)	::Praction::Log::GetCoreLogger()->info(__VA_ARGS__)
#define PT_CORE_WARN(...)	::Praction::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define PT_CORE_ERROR(...)	::Praction::Log::GetCoreLogger()->error(__VA_ARGS__)
#define PT_CORE_FATAL(...)	::Praction::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define PT_TRACE(...)		::Praction::Log::GetClientLogger()->trace(__VA_ARGS__)
#define PT_INFO(...)		::Praction::Log::GetClientLogger()->info(__VA_ARGS__)
#define PT_WARN(...)		::Praction::Log::GetClientLogger()->warn(__VA_ARGS__)
#define PT_ERROR(...)		::Praction::Log::GetClientLogger()->error(__VA_ARGS__)
#define PT_FATAL(...)		::Praction::Log::GetClientLogger()->fatal(__VA_ARGS__)
