#pragma once

#include "Core.h"
namespace Hazel {

	//�������Զ����� .lib�ļ��� .dll�ļ���
	class HAZEL_API Application
	{

	public:

		Application();

		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}