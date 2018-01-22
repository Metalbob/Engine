#pragma once

#include "Shader.h"

#include <map>
#include <string>
#include <GL/GL.h>

namespace Engine
{
	class Program
	{
		GLuint programID;
		std::map<const std::string, GLuint> attributesLocations;
		std::map<const std::string, GLuint> uniformsLocations;

	public:
		Program();
		~Program();

		void AttachShader(const Shader & shader);
		void LinkProgram();
		void UseProgram();
		void StopUseProgram();

		GLuint GetProgramID() const { return programID; }
		GLuint GetUniformLocation(const std::string & name);
		GLuint GetAttributeLocation(const std::string & name);
	};
}