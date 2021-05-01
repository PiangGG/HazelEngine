#pragma once

#include "Hazel/Core/Base.h"

namespace Hazel
{
	class  Input
	{
	public:
		static	bool IsKeyPressed(int keycode);
		static bool IsMouseButtonPressed(int button);
		 static std::pair<float, float> GetMousePosition();
		 static bool GetMouseX();
		 static bool GetMouseY();
	};
}