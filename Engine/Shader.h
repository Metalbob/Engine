#pragma once

#include <string>
#include <GL/glew.h>

namespace Engine
{
	class Shader
	{
		GLuint shaderID;
		//const char * GetFileContent(const char * fileName);
		std::string GetFileContent(const std::string & fileName);
		bool valid = false;

	public:
		enum EShaderType
		{
			VERTEX_SHADER,
			GEOMETRY_SHADER,
			FRAGMENT_SHADER
		};

		Shader() = default;
		~Shader() = default;

		GLuint GetShaderID() const { return shaderID; }
		bool IsValid() const { return valid; }

		void LoadShader(const char * fileName, EShaderType type);
	};
}
