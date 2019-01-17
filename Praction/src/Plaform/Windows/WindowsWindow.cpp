#include "ptpch.h"
#include "WindowsWindow.h"

#include "Praction/Events/ApplicationEvent.h"
#include "Praction/Events/MouseEvent.h"
#include "Praction/Events/KeyEvent.h"

#include <glad/glad.h>

namespace Praction {
	
	// s_GLFWInitialized checks if GLFW was already initialized
	static bool s_GLFWInitialized = false;

	static void GLFWErrorCallback(int error, const char* description)
	{
		PT_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
	}

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
			glfwSetErrorCallback(GLFWErrorCallback);

			s_GLFWInitialized = true;
		}

		// GLFW API to create a window
		m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);

		// Use Glad to load graphic's card libraries
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		PT_CORE_ASSERT(status, "Failed to initialize Glad!");

		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);

		// Set GLFW callbacks
		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			data.Width = width;
			data.Height = height;

			WindowResizeEvent event(width, height);
			data.EventCallback(event);
		});

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			WindowCloseEvent event;
			data.EventCallback(event);
		});

		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			switch (action)
			{
				case GLFW_PRESS:
				{
					KeyPressedEvent event(key, 0);
					data.EventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyReleasedEvent event(key);
					data.EventCallback(event);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPressedEvent event(key, 1);
					data.EventCallback(event);
					break;
				}
			}
		});

		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			switch (action)
			{
				case GLFW_PRESS:
				{
					MouseButtonPrssedEvent event(button);
					data.EventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonReleasedEvent event(button);
					data.EventCallback(event);
					break;
				}
			}
		});

		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			MouseScrolledEvent event((float)xOffset, (float)yOffset);
			data.EventCallback(event);
		});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPos, double yPos)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			MouseMovedEvent event((float)xPos, (float)yPos);
			data.EventCallback(event);
		});
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