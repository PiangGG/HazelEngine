#include <Hazel.h>
#include <Hazel/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace Hazel 
{
	class HazelEditor :public Application 
	{
	public:
		HazelEditor()
			:Application("HazelEngine Editor")
		{
			PushLayer(new EditorLayer());
		}
		~HazelEditor()
		{
			HZ_CORE_INFO("~EditorLayer()");
		}
	};

	Application* CreateApplication()
	{
	
		return new HazelEditor();
	}
}
