#pragma once

#include "Core.h"
namespace Hazel {

	//这样会自动产生 .lib文件和 .dll文件的
	class HAZEL_API Application
	{

	public:

		Application();

		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}