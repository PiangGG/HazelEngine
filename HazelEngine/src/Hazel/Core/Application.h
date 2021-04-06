#pragma once

#include "Hazel/Core/Core.h"
#include "Hazel/Events/Event.h"
#include "Hazel/Events/ApplicationEvent.h"
#include "Hazel/Core/Window.h"
#include "LayerStack.h"

#include "Hazel/ImGui/ImGuiLayer.h"
#include "Hazel/Core/Timestep.h"

namespace Hazel {

	//这样会自动产生 .lib文件和 .dll文件的
	class  Application
	{

	public:

		Application();

		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline static Application& Get() {	return *s_Instance;}
		inline Window& GetWindow() { return *m_Window; }
	private:
		bool OnWindowClose(WindowcloseEvent& e);
		bool OnWindowResize(WindowResizeEvnet& e);
	private:
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Runing = true;
		bool m_Minimized = false;
		LayerStack m_LayerStack;
		Timestep m_Timestep;
		float m_LastFramTime=0.0f;
	private:
		static Application* s_Instance;
	};

	Application* CreateApplication();

}