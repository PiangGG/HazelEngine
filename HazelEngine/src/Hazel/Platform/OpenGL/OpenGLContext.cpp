#include "hzpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include "glad/glad.h"
#include <GL/GL.h>
namespace Hazel 
{
	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		:m_windowHandle(windowHandle)
	{
		//HZ_CORE_(windowHandle,"Window handle is null");
	}
	void OpenGLContext::Init()
	{
		//^
		glfwMakeContextCurrent(m_windowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

	}
	void OpenGLContext::SwapBuffers()
	{
		glBegin();
		glEnd();
		glfwSwapBuffers(m_windowHandle);
	}
}