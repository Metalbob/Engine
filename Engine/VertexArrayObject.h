#pragma once

#include <vector>

#include <GL/glew.h>

#include "VertexBufferObject.h"

namespace Engine
{
	class VertexArrayObject
	{
		std::vector<VertexBufferObject *> vbos;

		int totalIndices;

	public:
		GLuint arrayID;
		VertexArrayObject();
		~VertexArrayObject();

		void Bind();
		void Unbind();

		void AddVBO(GLfloat * datas, unsigned int datasLength, GLuint * indices, unsigned int indicesLength);
		void Draw();
	};
}