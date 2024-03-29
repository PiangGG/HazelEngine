#pragma once

#include "Hazel/Events/Event.h"

namespace Hazel
{
	class  KeyEvent: public Event 
	{
	public:
		inline int GetKeyCode()const { return m_KeyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryInput|EventCategoryKeyboard)
	protected:
		KeyEvent(int keycode) :m_KeyCode(keycode) {}
			int m_KeyCode;
	};

	class  KeyPressedEvnet :public KeyEvent 
	{
	public:
		KeyPressedEvnet(int keycode,int repeatCount):KeyEvent(keycode),m_RepeatCount(repeatCount) {	}
	
		inline int GetRepeatCount()const { return m_RepeatCount; }

		std::string ToString()const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvnet:" << m_KeyCode << "(" << m_RepeatCount<<"repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
	private:
		int m_RepeatCount;
	};

	class  KeyReleasedEvnet :public KeyEvent
	{
	public:
		KeyReleasedEvnet(int keycode) :KeyEvent(keycode) {	}
	
		inline int GetRepeatCount()const { return m_RepeatCount; }

		std::string ToString()const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvnet:" << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	private:
		int m_RepeatCount;
	};
	class  KeyTypedEvent : public KeyEvent
	{
	public:
		KeyTypedEvent(int keycode)
			: KeyEvent(keycode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyTypedEvent: " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyTyped)
	};
}