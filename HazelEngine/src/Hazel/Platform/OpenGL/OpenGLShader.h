#pragma once

#include <glm/glm.hpp>
#include "Hazel/Renderer/Shader.h"

//TODO:REMOVE!
typedef unsigned int GLenum;

namespace Hazel
{
	class OpenGLShader:public Shader
	{
	public:
		OpenGLShader(const std::string& vertexSrc, const std::string& fragmentSrc);
		OpenGLShader(const std::string& filepath);
		virtual ~OpenGLShader();

		virtual void Bind()const override;
		virtual void UnBind()const override;

		void UploadUniformInt(const std::string& name, int values);

		void UploadUniformFloat1(const std::string& name, float values);
		void UploadUniformFloat2(const std::string& name, const glm::vec2& values);
		void UploadUniformFloat3(const std::string& name, const glm::vec3& values);
		void UploadUniformFloat4(const std::string& name, const glm::vec4& values);

		void UploadUniformMat3(const std::string& name, const glm::mat3& matrix);
		void UploadUniformMat4(const std::string& name, const glm::mat4& matrix);
	private:
		std::string ReadFile(const std::string& filepath);
		std::unordered_map<GLenum,std::string> PreProcess(const std::string& source);
		void Compile(std::unordered_map<GLenum, std::string>& shaderSource);
	private:
		uint32_t m_RendererID;
	};
}