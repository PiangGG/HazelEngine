#include "hzpch.h"
#include "Application.h" 
#include "Events/ApplicationEvent.h"
#include "Log.h"

#include <glad/glad.h>
namespace Hazel {

#define  BIND_EVENT_FN(x) std::bind(&Application::x,this,std::placeholders::_1)

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));

		unsigned int id;
		glGenVertexArrays(1, &id);
	}

	Application::~Application()
	{
	}

	void Application::PushLayer(Layer *layer) 
	{
		HZ_CORE_TRACE("Application::PushLayer");
		m_LayerStack.PushLayer(layer);
	}
	void Application::PushOverlay(Layer *layer)
	{
		m_LayerStack.PushOverlay(layer);
	}
	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowcloseEvent>(BIND_EVENT_FN(OnWindowClose));
		HZ_CORE_TRACE("{0}",e);

		for (auto it=m_LayerStack.end(); it!=m_LayerStack.begin();)
		{
			(*--it)->OnEvent(e);
			if (e.Handled)
				break;
		}
	}

	bool Application::OnWindowClose(WindowcloseEvent& e)
	{
		m_Runing = false;
		return true;
	}
	void Application::Run()
	{
		//HZ_TRACE(e);
		while (m_Runing) 
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			/*for (Layer* layer:m_LayerStack.m_Layers) 
			{
				layer->OnUpdate();
			}*/
			//HZ_CORE_TRACE("m_LayerStack.Count():{0}", m_LayerStack.m_Layers.size());
			
			m_Window->OnUpdate();
		}
	}

	
}