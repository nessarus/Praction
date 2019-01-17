#pragma once

#include "Core.h"

#include "Window.h"
#include "Praction/LayerStack.h"
#include "Praction/Events/Event.h"
#include "Praction/Events/ApplicationEvent.h"


namespace Praction {
	
	// Application is a class that allow other projects to launch the game engine's applications
	class PRACTION_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline Window& GetWindow() { return *m_Window; }
		inline static Application& Get() { return *s_Instance; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);


		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	private:
		static Application* s_Instance;
	};

	// Allows projects to create a new game engine application object
	// Client impliments method
	Application* CreateApplication();


}

