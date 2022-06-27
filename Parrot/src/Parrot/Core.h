#pragma once

#ifdef PARROT_PLATFORM_WINDOWS
	#ifdef PARROT_BUILD_DLL
		#define PARROT_API __declspec(dllexport)
	#else
		#define PARROT_API __declspec(dllimport)
	#endif // PARROT_BUILD_DLL
#else
	#error PARROT Only Suppport Windows
#endif // PARROT_PLATFORM_WINDOWS

#ifdef PT_ENABLE_ASSERTS
	#define PT_ASSERT(x, ...)                               \
		if (!(x))                                           \
		{                                                   \
			PT_ERROR("Assertion Failed: {0}", __VA_ARGS__); \
			__debugbreak();                                 \
		}
	#define PT_CORE_ASSERT(x, ...)                               \
		if (!(x))                                                \
		{                                                        \
			PT_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); \
			__debugbreak();                                      \
		}
#else
	#define PT_ASSERT(x, ...)
	#define PT_CORE_ASSERT(x, ...)
#endif // PT_ENABLE_ASSERTS

#define BIT(x) (1 << x)
