#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Window.h"
#include "LayerStack.h"

#include "ImGui/ImGuiLayer.h"

#include "Hazel/Renderer/Shader.h"
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

		inline static Application& Get() {	return *s_Instance;}
		inline Window& GetWindow() { return *m_Window; }
	private:

		bool OnWindowClose(WindowcloseEvent& e);
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Runing = true;

		LayerStack m_LayerStack;

		unsigned int m_VertexArray, m_VertexBuffer, m_IndexBuffer;
		std::unique_ptr<Shader> m_Shader;
	private:
		static Application* s_Instance;
	};

	Application* CreateApplication();

}