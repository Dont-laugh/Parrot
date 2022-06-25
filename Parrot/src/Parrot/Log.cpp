#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Parrot
{
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	static std::string PATTERN = "%^[%Y-%m-%d %H:%M:%S.%e] [%n] [%l]%$ %v";

	void Log::Init()
	{
		// https://github.com/gabime/spdlog/wiki/3.-Custom-formatting
		spdlog::set_pattern(PATTERN);

		s_CoreLogger = spdlog::stdout_color_mt("PARROT");
		s_CoreLogger->set_level(spdlog::level::trace);
		PT_CORE_TRACE("Core logger named PARROT has been created.");

		s_ClientLogger = spdlog::stdout_color_mt("CLIENT");
		s_ClientLogger->set_level(spdlog::level::trace);
		PT_TRACE("Client logger named CLIENT has been created.");
	}
}
