#include "stdafx.h"
#include "Program.h"
#include "Logger.h"

namespace Engine
{
	Program::Program()
	{
		programID = glCreateProgram();
	}

	void Program::AttachShader(const Shader & shader)
	{
		if (!shader.IsValid())
		{
			Logger::LogError("Try to attach invalid shader.");
			return;
		}

		glAttachShader(programID, shader.GetShaderID());
	}

	void Program::LinkProgram()
	{
		glLinkProgram(programID);
		GLint programSuccess = GL_TRUE;
		glGetProgramiv(programID, GL_LINK_STATUS, &programSuccess);
		if (programSuccess != GL_TRUE)
		{
			Logger::LogError("Error linking program");
		}



		GLint i;																				//
		GLint count;																			//
																								//
		GLint size; 																			//
		GLenum type; 																			//
																								//
		const GLsizei bufSize = 32; 															//
																								//
		GLchar name[bufSize]; 																	//
		GLsizei length; 																		//
																								//
																								//
		glGetProgramiv(programID, GL_ACTIVE_ATTRIBUTES, &count);								//  code a clean
																								//
		for (int i = 0; i < count; i++)															//
		{																						//
			glGetActiveAttrib(programID, (GLuint)i, bufSize, &length, &size, &type, name);		//
			attributesLocations[name] = glGetAttribLocation(programID, name);					//
		}																						//
																								//
		glGetProgramiv(programID, GL_ACTIVE_UNIFORMS, &count);									//
																								//
		for (i = 0; i < count; i++)																//
		{																						//
			glGetActiveUniform(programID, (GLuint)i, bufSize, &length, &size, &type, name);		//
			uniformsLocations[name] = glGetUniformLocation(programID, name);					//
		}																						//
	}

	GLuint Program::GetUniformLocation(const std::string & name)
	{
		return uniformsLocations[name];
	}

	GLuint Program::GetAttributeLocation(const std::string & name)
	{
		return attributesLocations[name];
	}

	void Program::UseProgram()
	{
		glUseProgram(programID);

		for (std::map< const std::string, GLuint>::iterator it = attributesLocations.begin(); it != attributesLocations.end(); it++)
			glEnableVertexAttribArray(it->second);
	}

	void Program::StopUseProgram()
	{
		for (std::map< const std::string, GLuint>::iterator it = attributesLocations.begin(); it != attributesLocations.end(); it++)
			glDisableVertexAttribArray(it->second);

		glUseProgram(0);
	}

	Program::~Program()
	{
	}
}