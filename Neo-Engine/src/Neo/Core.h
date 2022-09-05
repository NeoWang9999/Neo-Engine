#pragma once

#ifdef NEO_PLATFORM_WINDOWS

	#ifdef NEO_BUILD_DLL
		#define NEO_API __declspec(dllexport)
	#else
		#define NEO_API __declspec(dllimport)
	#endif // NEO_BUILD_DLL

#else
	#error Neo Only supports Windows!

#endif // NEO_PLATFORM_WINDOWS


#define BIT(x)  1 << x

