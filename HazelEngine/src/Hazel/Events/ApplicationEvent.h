#pragma once

#include "Hazel/Events/Event.h"

namespace Hazel 
{
	class  WindowResizeEvnet : public Event 
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

	class  WindowcloseEvent :public Event 
	{
	public:
		WindowcloseEvent() = default;

		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class  AppTickEvent :public Event 
	{
	public:
		AppTickEvent() = default;

		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class  AppUpdateEvent :public Event
	{
	public:
		AppUpdateEvent() = default;

		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class  AppRenderEvent :public Event
	{
	public:
		AppRenderEvent() = default;

		EVENT_CLASS_TYPE(AppRender)

		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

}