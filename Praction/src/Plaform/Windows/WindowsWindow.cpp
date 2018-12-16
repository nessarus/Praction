#include "ptpch.h"
#include "WindowsWindow.h"

namespace Praction {
	
	// s_GLFWInitialized checks if GLFW was already initialized
	static bool s_GLFWInitialized = false;

	// Implimentation to create a window (platform: Microsoft Windows)
	Window* Window::Create(const WindowProps& props)
	{
		return new WindowsWindow(props);
	}

	// Window Constructor
	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		Init(props);
	}

	// Window Deconstructor
	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}

	// Window Constructor Initializiation
	void WindowsWindow::Init(const WindowProps& props)
	{
		// sets window data
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		// logs stuff
		PT_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

		// checkes if GLFW was already initialized
		if (!s_GLFWInitialized)
		{
			// TODO: glfwTerminate on system shutdown
			int success = glfwInit();

			// checks if GLFW was able to initialize
			PT_CORE_ASSERT(success, "Could not intialize GLFW!");

			s_GLFWInitialized = true;
		}

		// GLFW API to create a window
		m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);
	}

	// Shutdown destroys the window
	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(m_Window);
	}

	// Updating window per frame
	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	// Enabling VSync
	void WindowsWindow::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		m_Data.VSync = enabled;
	}

	// Getter to see if vsync is on
	bool WindowsWindow::IsVSync() const
	{
		return m_Data.VSync;
	}
}