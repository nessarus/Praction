#pragma once

#include "Event.h"

#include <sstream>

namespace Praction {
	
	// key events are when the user presses keys on keyboard

	// base class 
	class PRACTION_API KeyEvent : public Event
	{
	public:
		// function returns the key code
		inline int GetKeyCode() const { return m_KeyCode; }

		// macro to categorize event into categories
		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

	protected:
		// protected constructor (no other class can construct it)
		KeyEvent(int keycode)
			: m_KeyCode(keycode) {}

		// the actual key code
		int m_KeyCode;
	};

	// key press is when the user initially presses down on the key
	class PRACTION_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keycode, int repeatCount)
			: KeyEvent(keycode), m_RepeatCount(repeatCount) {}

		inline int GetRepeatCount() const { return m_RepeatCount;  }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
			return ss.str();
		}

		// macro to set the base event get functions
		EVENT_CLASS_TYPE(KeyPressed)

	private:
		int m_RepeatCount;
	};

	class PRACTION_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keycode)
			: KeyEvent(keycode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};
}

