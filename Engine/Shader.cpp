#include "stdafx.h"

#include <iostream>

#include <fstream>
#include <sstream>

#include "Logger.h"
#include "Shader.h"


namespace Engine
{
	std::string Shader::GetFileContent(const std::string & fileName)
	{
		std::ifstream fichier(fileName.c_str());

		if (fichier)
		{
			std::stringstream buffer;
			buffer << fichier.rdbuf();
			fichier.close();
			std::string source(buffer.str());
			source.push_back('\0');
			return source;
		}
	}

	void Shader::LoadShader(const char * fileName, EShaderType type)
	{
		std::string fileContent = GetFileContent(fileName);

		if (type == EShaderType::VERTEX_SHADER)
			shaderID = glCreateShader(GL_VERTEX_SHADER);
		else if (type == EShaderType::GEOMETRY_SHADER)
			shaderID = glCreateShader(GL_GEOMETRY_SHADER);
		else if (type == EShaderType::FRAGMENT_SHADER)
			shaderID = glCreateShader(GL_FRAGMENT_SHADER);

		const char * content = fileContent.c_str();

		glShaderSource(shaderID, 1, &content, nullptr);

		glCompileShader(shaderID);

		GLint error;
		glGetShaderiv(shaderID, GL_COMPILE_STATUS, &error);
		if (error != GL_TRUE)
		{
			Logger::LogError("Shader didn't compiled.");

			GLint maxLength = 0;
			glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &maxLength);

			GLchar * errorLog = new GLchar[maxLength];
			glGetShaderInfoLog(shaderID, maxLength, &maxLength, &errorLog[0]);

			Logger::LogError(errorLog);

			glDeleteShader(shaderID);
			
			return;
		}

		valid = true;
	}
}