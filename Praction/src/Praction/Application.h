#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Praction/Events/ApplicationEvent.h"


#include "Window.h"

namespace Praction {
	
	// Application is a class that allow other projects to launch the game engine's applications
	class PRACTION_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

	private:
		bool OnWindowClose(WindowCloseEvent& e);


		std::unique_ptr<Window> m_Window;
		bool m_Running = true;

	};

	// Allows projects to create a new game engine application object
	// Client impliments method
	Application* CreateApplication();


}

