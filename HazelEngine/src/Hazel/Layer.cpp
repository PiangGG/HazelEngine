#include "hzpch.h"
#include "Layer.h"

namespace Hazel 
{
	Layer::Layer(const std::string& debugName):m_DebugName(debugName) 
	{
		HZ_CORE_TRACE("InitLayer");
	}

	Layer ::~Layer()
	{
		
	}
}