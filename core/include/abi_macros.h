#pragma once

#ifdef _WIN32
    #define PMB_PLATFORM_WINDOWS 1
#elif defined(__linux__)
    #define PMB_PLATFORM_LINUX 1
#elif defined(__APPLE__)
    #define PMB_PLATFORM_MACOS 1
#endif

#ifdef PMB_PLATFORM_WINDOWS
    #ifdef PMB_BUILDING
        #define PMB_API __declspec(dllexport)
    #else
        #define PMB_API __declspec(dllimport)
    #endif
#else
    #ifdef PMB_BUILDING
        #define PMB_API __attribute__((visibility("default")))
    #else
        #define PMB_API
    #endif
#endif

#ifdef PMB_PLATFORM_WINDOWS
    #if defined(_M_IX86)
        #define PMB_CALL __cdecl
    #else
        #define PMB_CALL
    #endif
#else
    #define PMB_CALL
#endif


#ifdef __cplusplus
    #define PMB_EXTERN_C_BEGIN extern "C" {
    #define PMB_EXTERN_C_END }
#else
    #define PMB_EXTERN_C_BEGIN
    #define PMB_EXTERN_C_END
#endif