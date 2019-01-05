#include <Praction.h>

// Example on how to impliment the praction layer class
class ExampleLayer : public Praction::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		PT_INFO("ExampleLayer::Update");
	}

	void OnEvent(Praction::Event& event) override
	{
		PT_TRACE("{0}", event);
	}
};

// creates a class that inherits from game engines's application class
class Sandbox : public Praction::Application
{
public:
	Sandbox()
	{
		// example of how to contruct and add a layer to the layer stack.
		PushLayer(new ExampleLayer());
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