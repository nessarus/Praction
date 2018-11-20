#include <Praction.h>

// creates a class that inherits from game engines's application class
class Sandbox : public Praction::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

// CreateApplication allows Sandbox to create a new game engine application object
Praction::Application* Praction::CreateApplication()
{
	return new Sandbox();
}