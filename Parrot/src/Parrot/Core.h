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

#define BIT(x) (1 << x)
