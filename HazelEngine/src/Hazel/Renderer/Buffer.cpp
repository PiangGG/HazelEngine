#include "hzpch.h"
#include "Buffer.h"
#include "Renderer.h"
#include "Hazel/Platform/OpenGL/OpenGLBuffer.h"


namespace Hazel 
{
	VertexBuffer* VertexBuffer::Create(float* vertices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:HZ_CORE_ERROR("RendererAPI::None return nullptr"); return nullptr;
			case RendererAPI::API::OpenGL:
			{
				return new OpenGLVertexBuffer(vertices,size);
			}
		}
		HZ_CORE_ERROR("Unkown RenderAPI");
		return nullptr;
	}

	IndexBuffer* IndexBuffer::Create(uint32_t* indices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:HZ_CORE_ERROR("RendererAPI::None return nullptr"); return nullptr;
			case RendererAPI::API::OpenGL:
			{
				return new OpenGLIndexBuffer(indices, size);
			}
		}
		HZ_CORE_ERROR("Unkown RenderAPI");
		return nullptr;
	}

}
