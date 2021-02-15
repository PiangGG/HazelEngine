#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Window.h"
#include "LayerStack.h"
namespace Hazel {

	//这样会自动产生 .lib文件和 .dll文件的
	class HAZEL_API Application
	{

	public:

		Application();

		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
	private:

		bool OnWindowClose(WindowcloseEvent& e);
		std::unique_ptr<Window> m_Window;
		bool m_Runing = true;

		LayerStack m_LayerStack;
	};

	Application* CreateApplication();

}