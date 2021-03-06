#pragma once

#include "Event.h"

namespace Hazel 
{
	class HAZEL_API WindowResizeEvnet : public Event 
	{
	public:
		WindowResizeEvnet(unsigned int width, unsigned int height) 
		:m_width(width),m_height(height){}

		inline unsigned int GetWidth()const { return m_width; }
		inline unsigned int GetHeight()const { return m_height; }

		std::string ToString()const override 
		{
			std::stringstream ss;
			ss << "WindowResizeEvnet:" << m_width << "," << m_height;
			return ss.str();
		}
		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

	private:
		unsigned int m_width,m_height;
	};

	class HAZEL_API WindowcloseEvent :public Event 
	{
	public:
		WindowcloseEvent() {};

		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class HAZEL_API AppTickEvent :public Event 
	{
	public:
		AppTickEvent() {};

		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class HAZEL_API AppUpdateEvent :public Event
	{
	public:
		AppUpdateEvent() {};

		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class HAZEL_API AppRenderEvent :public Event
	{
	public:
		AppRenderEvent() {};

		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

}