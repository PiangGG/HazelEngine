#include "hzpch.h"
#include "Application.h" 
#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace Hazel {

	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvnet e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			HZ_CORE_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			HZ_CORE_TRACE(e);
		}
		//HZ_TRACE(e);
		while (true);	
	}

	
}