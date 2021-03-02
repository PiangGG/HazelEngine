#include <Hazel.h>
#include "imgui/imgui.h"

class ExampleLayer : public Hazel::Layer 
{
public :
	ExampleLayer() :Layer("Example") 
	{
		
	}
	void OnUpdate()override
	{
	
	}
	virtual void OnImGuiRender()override 
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello World");
		ImGui::End();
	}
	void OnEvent(Hazel::Event& event) override
	{
		if (Hazel::Input::IsKeyPressed(HZ_KEY_TAB))
		{
			HZ_CORE_INFO("TAB KEY IS PRESSED");
		}
		if (event.GetEventType()==Hazel::EventType::KeyPressed)
		{
			Hazel::KeyPressedEvnet& e = (Hazel::KeyPressedEvnet&)event;
			HZ_CORE_TRACE("{0}",(char)e.GetKeyCode());
		}
	}
};

class Sandbox :public Hazel::Application 
{
public:
	Sandbox() 
	{
		PushLayer(new ExampleLayer());
		
	}
	~Sandbox() 
	{
		HZ_CORE_INFO("~Sandbox()");
	}
};

Hazel::Application* Hazel::CreateApplication()
{
	
	return new Sandbox();
}