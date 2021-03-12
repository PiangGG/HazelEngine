#include "hzpch.h"
#include "Application.h" 
#include "Events/ApplicationEvent.h"
#include "Log.h"
#include "Renderer/Renderer.h"
#include "Input.h"
#include "glm/glm.hpp"


namespace Hazel {

#define  BIND_EVENT_FN(x) std::bind(&Application::x,this,std::placeholders::_1)

	Application* Application::s_Instance = nullptr;

	
	Application::Application()
	{
		s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));

		m_ImGuiLayer = new ImGuiLayer();

		PushOverlay(m_ImGuiLayer);
		
		
	}

	Application::~Application()
	{
	}

	void Application::PushLayer(Layer *layer) 
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}
	void Application::PushOverlay(Layer *layer)
	{
		m_LayerStack.PushOverlay(layer);
		layer->OnAttach();
	}
	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowcloseEvent>(BIND_EVENT_FN(OnWindowClose));
		
	
		/*if (e.GetEventType() == EventType::MouseScrolled)
		{
			MouseScrolledEvent* the = dynamic_cast<MouseScrolledEvent*>(&e);
			HZ_CORE_TRACE("{0}", e);
			m_Camera.SetPosition({cf+=the->GetYOffset()/10, cf+=the->GetYOffset()/10, 0.0f});
		}*/
		
		/*for (auto it=m_LayerStack.end(); it!=m_LayerStack.begin();)
		{
			(*--it)->OnEvent(e);
			if (e.Handled)
				break;
		}*/
		for (auto it = m_LayerStack.rbegin(); it != m_LayerStack.rend(); ++it)
		{
			if (e.Handled)
				break;
			(*it)->OnEvent(e);
		}
	}

	bool Application::OnWindowClose(WindowcloseEvent& e)
	{
		m_Runing = false;
		return true;
	}
	void Application::Run()
	{
		while (m_Runing)
		{
		
			for (Layer* layer:m_LayerStack) 
			{
				layer->OnUpdate();
			}
			m_ImGuiLayer->Begin();
			for (Layer* layer : m_LayerStack)
			{
				layer->OnImGuiRender();
			}
			m_ImGuiLayer->End();
			
			m_Window->OnUpdate();
		}
	}
}