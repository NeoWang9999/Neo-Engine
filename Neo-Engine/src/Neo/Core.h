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


#ifdef NEO_ENABLE_ASSERTS
    #define NEO_ASSERT(x, ...) { if(!(x)) { NEO_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
    #define NEO_CORE_ASSERT(x, ...) { if(!(x)) { NEO_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
    #define NEO_ASSERT(x, ...)
    #define NEO_CORE_ASSERT(x, ...)
#endif // NEO_ENABLE_ASSERTS


#define BIT(x)  1 << x
