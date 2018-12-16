#pragma once

#include "ptpch.h"

#include "Praction/Core.h"
#include "Praction/Events/Event.h"

namespace Praction {

	struct WindowProps
	{
		// Window properties
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		// default values of title, width and height if not specified
		WindowProps(
			const std::string& title = "Praction Engine",
			unsigned int width = 1280,
			unsigned int height = 720
		) : Title(title), Width(width), Height(height)
		{
		}
	};

	// Interface representing a destop system based Window
	class PRACTION_API Window
	{
	public:
		// Event call back function
		using EventCallbackFn = std::function<void(Event&)>;

		// Virtual destructor
		virtual ~Window() {}

		// Various virtual window methods
		virtual void OnUpdate() = 0;
		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		// Window attributes
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		// Virtual method to create the window (implimented per platform)
		static Window* Create(const WindowProps& props = WindowProps());
	};
	// All methods are virtual (no data or functions)
	// These methods will be implimented per platform
}