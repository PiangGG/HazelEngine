#include "hzpch.h"
#include "VertexArray.h"
#include "Renderer.h"
#include "Hazel/Platform/OpenGL/OpenGLVertexArray.h"

namespace Hazel 
{
	VertexArray* VertexArray::Create() 
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::None:HZ_CORE_ERROR("RendererAPI::None return nullptr"); return nullptr;
			case RendererAPI::OpenGL:return new OpenGLVertexArray();
		}
		HZ_CORE_ERROR("Unkown RenderAPI");
		return nullptr;
	}
}