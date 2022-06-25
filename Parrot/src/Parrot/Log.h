#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Parrot
{
	class PARROT_API Log
	{
	public:
		static void Init();

		__forceinline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		__forceinline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core logger macros
#define PT_CORE_TRACE(...) ::Parrot::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define PT_CORE_LOG(...) ::Parrot::Log::GetCoreLogger()->info(__VA_ARGS__)
#define PT_CORE_WARN(...) ::Parrot::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define PT_CORE_ERROR(...) ::Parrot::Log::GetCoreLogger()->error(__VA_ARGS__)
#define PT_CORE_FATAL(...) ::Parrot::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client logger macros
#define PT_TRACE(...) ::Parrot::Log::GetClientLogger()->trace(__VA_ARGS__)
#define PT_LOG(...) ::Parrot::Log::GetClientLogger()->info(__VA_ARGS__)
#define PT_WARN(...) ::Parrot::Log::GetClientLogger()->warn(__VA_ARGS__)
#define PT_ERROR(...) ::Parrot::Log::GetClientLogger()->error(__VA_ARGS__)
#define PT_FATAL(...) ::Parrot::Log::GetClientLogger()->critical(__VA_ARGS__)
