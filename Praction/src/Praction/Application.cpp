#include "ptpch.h"
#include "Application.h"

#include "Praction/Events/ApplicationEvent.h"
#include "Praction/Log.h"

namespace Praction {
	Application::Application()
	{
	}


	Application::~Application()
	{
	}

	// game engine's application run loop
	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			PT_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			PT_TRACE(e);
		}

		while (true);
	}
}

