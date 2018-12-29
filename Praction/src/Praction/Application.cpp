#include "ptpch.h"
#include "Application.h"

#include "Praction/Log.h"

#include <GLFW/glfw3.h>

namespace Praction {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}


	Application::~Application()
	{
	}

	void Application::OnEvent(Event & e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

		PT_CORE_TRACE("{0}", e);
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

	bool Application::OnWindowClose(WindowCloseEvent & e)
	{
		m_Running = false;
		return true;
	}

}

