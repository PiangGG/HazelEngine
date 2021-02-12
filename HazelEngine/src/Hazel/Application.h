#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Window.h"
namespace Hazel {

	//这样会自动产生 .lib文件和 .dll文件的
	class HAZEL_API Application
	{

	public:

		Application();

		virtual ~Application();

		void Run();

		void OnEvent(Event& e);
	private:

		bool OnWindowClose(WindowcloseEvent& e);
		std::unique_ptr<Window> m_Window;
		bool m_Runing = true;

	};

	Application* CreateApplication();

}