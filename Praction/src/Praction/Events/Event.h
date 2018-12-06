#pragma once

#include "Praction/Core.h"

#include <string>
#include <functional>

namespace Praction {
	// Praction is currently using blocking code to handle events.

	// A class to differentiate different types of events (i.e. not just using int)
	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	// EventCategory allows filtering of events. See definition of BIT in CORE.h
	enum EventCategory
	{
		None = 0,
		EventCategoryApplication	= BIT(0),
		EventCategoryInput			= BIT(1),
		EventCategoryKeyboard		= BIT(2),
		EventCategoryMouse			= BIT(3),
		EventCategoryMouseButton	= BIT(4)
	};

	// macros to impliment the three type, name and flag virtual funtions in base event class 
#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	// base class for events
	class PRACTION_API Event
	{
		friend class EventDispatcher;
	public:
		// event type, name and flags get functions
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;

		// returns the name of the event (for debugging)
		virtual std::string ToString() const { return GetName(); }

		// function to check if the event in in a particular category
		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}
	protected:
		// stores if the event has been already handled
		bool m_Handled = false;
	};

	// Dispatcher recieves a reference to an event (Event& event)
	// We can then call a differnt event function (EventFn<T> func) for each event
	class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event)
			: m_Event(event)
		{
		}

		template<typename T> 
		bool Dispatch(EventFn<T> func)
		{
			// checks if the event matches with the dispatch arguement
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.m_Handled = func(*(T*)&m_Event);
				return true;
			}
			return false;
		}
	private:
		Event& m_Event;
	};
								
	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}
}