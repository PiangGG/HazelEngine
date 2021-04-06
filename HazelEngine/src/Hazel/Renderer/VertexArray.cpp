#include "hzpch.h"
#include "Hazel/Renderer/VertexArray.h"

#include "Hazel/Renderer/Renderer.h"
#include "Hazel/Platform/OpenGL/OpenGLVertexArray.h"

namespace Hazel 
{
	Ref<VertexArray> VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:HZ_CORE_ERROR("RendererAPI::None return nullptr"); return nullptr;
			case RendererAPI::API::OpenGL:return CreateRef<OpenGLVertexArray>();
		}
		HZ_CORE_ERROR("Unkown RenderAPI");
		return nullptr;
	}
}