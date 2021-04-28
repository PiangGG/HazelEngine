#include "hzpch.h"
#include "Framebuffer.h"

#include "Hazel/Renderer/Renderer.h"

#include "Hazel/Platform/OpenGL/OpenGLFramebuffer.h"

namespace Hazel {

	Ref<Framebuffer> Framebuffer::Create(const FramebufferSpecification& spec)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:    HZ_CORE_ERROR( "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:  return CreateRef<OpenGLFramebuffer>(spec);
		}

		HZ_CORE_ERROR("Unknown RendererAPI!");
		return nullptr;
	}

}