#pragma once

#ifdef HZ_PLATFORM_WINDOWS
#if HZ_DYNAMIC_LINK
	#ifdef HZ_BUILD_DLL
		#define HAZEL_API _declspec(dllexport)
	#else 
		#define HAZEL_API _declspec(dllimport)
	#endif // DEBUG
#else
	#define HAZEL_API
#endif
#else
	#error Hzael only support Windows!
#endif // HZ_PLATFORM_WINDOWS

#ifdef HZ_DEBUG
	#define HZ_ENABLE_ASSERTS
#endif

#ifdef HZ_ENABLE_ASSERTS
	#define HZ_ASSERT(X,...){if(!(x)){HZ_ERROR(Assertion Failed:(0),__VA_ARGS__);__debugbreak();}}
	#define HZ_CORE_ASSERT(X,...){if(!(x)){HZ_ERROR(Assertion Failed:(0),__VA_ARGS__);__debugbreak();}}
#else
	#define HZ_ASSERT(X,...)
	#define HZ_CORE_ASSERT(X,...)
#endif // HZ_ENABLE_ASSERTS
	
#define BIT(x)(1<<x)

#define HZ_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)