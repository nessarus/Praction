#pragma once

#include "Core.h"


namespace Praction {
	
	// Application is a class that allow other projects to launch the game engine's applications
	class PRACTION_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// Allows projects to create a new game engine application object
	Application* CreateApplication();


}

