#include "hzpch.h"
#include "Hazel/Core/Application.h" 
#include "Hazel/Events/ApplicationEvent.h"
#include "Log.h"
#include "Hazel/Renderer/Renderer.h"
#include "Hazel/Core/Input.h"
#include "glm/glm.hpp"
#include <glfw/glfw3.h>

namespace Hazel {

	Application* Application::s_Instance = nullptr;

	
	Application::Application(const std::string& name)
	{
		HZ_PROFILE_FUNCTION();

		s_Instance = this;

		m_Window = Window::Create(WindowProps(name));
		m_Window->SetEventCallback(HZ_BIND_EVENT_FN(Application::OnEvent));

		Renderer::Init();

		m_ImGuiLayer = new ImGuiLayer();

		PushOverlay(m_ImGuiLayer);
		
		
	}

	Application::~Application()
	{
		HZ_PROFILE_FUNCTION();

		Renderer::Shutdown();
	}

	void Application::PushLayer(Layer *layer) 
	{
		HZ_PROFILE_FUNCTION();
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}
	void Application::PushOverlay(Layer *layer)
	{
		HZ_PROFILE_FUNCTION();
		m_LayerStack.PushOverlay(layer);
		layer->OnAttach();
	}
	void Application::OnEvent(Event& e)
	{
		HZ_PROFILE_FUNCTION();

		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowcloseEvent>(HZ_BIND_EVENT_FN(Application::OnWindowClose));
		dispatcher.Dispatch<WindowResizeEvnet>(HZ_BIND_EVENT_FN(Application::OnWindowResize));
		
		for (auto it = m_LayerStack.rbegin(); it != m_LayerStack.rend(); ++it)
		{
			if (e.Handled)
				break;
			(*it)->OnEvent(e);
		}
	}

	void Application::Close()
	{
		m_Running = false;
	}

	bool Application::OnWindowClose(WindowcloseEvent& e)
	{
		m_Running = false;
		return true;
	}
	bool Application::OnWindowResize(WindowResizeEvnet& e)
	{
		HZ_PROFILE_FUNCTION();

		if (e.GetWidth()==0||e.GetHeight()==0)
		{
			m_Minimized = true;
			return false;
		}
		m_Minimized = false;
		Renderer::OnWindowResize(e.GetWidth(),e.GetHeight());
		return false;
	}
	void Application::Run()
	{
		HZ_PROFILE_FUNCTION();

		while (m_Running)
		{
			HZ_PROFILE_SCOPE("RunLoop");
			
			float time = (float)glfwGetTime(); //Platform::GetTime()
			Timestep timestep = time - m_LastFramTime;
			m_LastFramTime = time;

			if (!m_Minimized)
			{
				{
					HZ_PROFILE_SCOPE("LayerStack OnUpdate");

					for (Layer* layer:m_LayerStack) 
					{
						layer->OnUpdate(timestep);
					}
				}

				m_ImGuiLayer->Begin();
				{
					HZ_PROFILE_SCOPE("LayerStack OnImGuiRender");
					for (Layer* layer : m_LayerStack)
					{
						layer->OnImGuiRender();
					}
				}
				m_ImGuiLayer->End();
			}
			m_Window->OnUpdate();
		}
	}
}