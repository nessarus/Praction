#pragma once

// defining the windows platform library's exporting and importing function
#ifdef PT_PLATFORM_WINDOWS
	#ifdef PT_BUILD_DLL
		#define PRACTION_API __declspec(dllexport)
	#else
		#define PRACTION_API __declspec(dllimport)
	#endif
#else
	#error Praction only supports Windows!
#endif

// PT_ENABLE_ASSERTS checkes if the program is in debug or release, then adds or removes assert statements accordingly
#ifdef PT_ENABLE_ASSERTS
	// ASSERTS checks a certain condition then inserts a breakpoint (windows only at the moment)
	#define PT_ASSERT(x, ...) { if(!(x)) { PT_EROOR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define PT_CORE_ASSERT(x, ...) { if(!(x)) { PT_CORE_ERROR("Assertion Failed: {0}", __VA__ARGS__); __debugbreak(); } }
#else
	#define PT_ASSERT(x, ...)
	#define PT_CORE_ASSERT(x, ...)
#endif


// BIT(x) is shift 1 to x place i.e. BIT(2) is 100
// This is to allow events to belong to multiple categories.
#define BIT(x) (1 << x)

#define PT_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1));