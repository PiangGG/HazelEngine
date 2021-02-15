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
		HZ_CORE_INFO("ExampleLayer::OnUpdate");
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