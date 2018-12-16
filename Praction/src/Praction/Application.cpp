#include "ptpch.h"
#include "Application.h"

#include "Praction/Log.h"
#include "Praction/Events/ApplicationEvent.h"

#include <GLFW/glfw3.h>

namespace Praction {
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}


	Application::~Application()
	{
	}

	// game engine's application run loop
	void Application::Run()
	{

		while (m_Running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}
}

