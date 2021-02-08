#pragma once

#include "Event.h"

#include <sstream>

namespace Hazel
{
	class HAZEL_API KeyEvent: public Event 
	{
	public:
		inline int GetKeyCode()const { return m_KeyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryInput|EventCategoryKeyboard)
	protected:
		KeyEvent(int keycode) :m_KeyCode(keycode) {}
			int m_KeyCode;
	};

	class HAZEL_API KeyPressedEvnet :public KeyEvent 
	{
		KeyPressedEvnet(int keycode,int repeatCount):KeyEvent(keycode),m_RepeatCount(repeatCount) {	}
	public:
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

	class HAZEL_API KeyReleasedEvnet :public KeyEvent
	{
		KeyReleasedEvnet(int keycode) :KeyEvent(keycode) {	}
	public:
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
}