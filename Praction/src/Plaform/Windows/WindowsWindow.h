#pragma once

#include "Praction/Window.h"

#include <GLFW/glfw3.h>

namespace Praction {

	// A simple implimentation of the Window's class interface for Microsoft Windows
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		// OnUpdate updates GLFW, swap buffers, poll input events, etc...
		void OnUpdate() override;

		// Getters methods
		inline unsigned int GetWidth() const override { return m_Data.Width;; }
		inline unsigned int GetHeight() const override { return m_Data.Height; }

		// Window attributes
		inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();

	private:
		GLFWwindow* m_Window;

		// WindowData is a structure that stores the window's data and enables us 
		// to pass it to GLFW.
		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;

			EventCallbackFn EventCallback;
		};

		WindowData m_Data;
	};
}