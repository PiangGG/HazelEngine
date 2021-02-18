#include <Hazel.h>

class ExampleLayer : public Hazel::Layer 
{
public :
	ExampleLayer() :Layer("Example") 
	{
		HZ_CORE_INFO("ExampleLayer::ExampleLayer");
	}
	void OnUpdate()override
	{

	}

	void OnEvent(Hazel::Event& event) override
	{
		HZ_CORE_TRACE("{0}",event);
	}
};

class Sandbox :public Hazel::Application 
{
public:
	Sandbox() 
	{
		PushLayer(new ExampleLayer());
		//new ExampleLayer();
		PushOverlay(new Hazel::ImGuiLayer());
		//PushLayer(new Hazel::ImGuiLayer());
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