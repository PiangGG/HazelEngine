#include "hzpch.h"
#include "VertexArray.h"
#include "Renderer.h"
#include "Hazel/Platform/OpenGL/OpenGLVertexArray.h"

namespace Hazel 
{
	Ref<VertexArray> VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:HZ_CORE_ERROR("RendererAPI::None return nullptr"); return nullptr;
			case RendererAPI::API::OpenGL:return std::make_shared<OpenGLVertexArray>();
		}
		HZ_CORE_ERROR("Unkown RenderAPI");
		return nullptr;
	}
}