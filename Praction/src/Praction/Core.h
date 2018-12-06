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
	
// BIT(x) is shift 1 to x place i.e. BIT(2) is 100
// This is to allow events to belong to multiple categories.
#define BIT(x) (1 << x)