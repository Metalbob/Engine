#pragma once

#include <GL/glew.h>

namespace Engine
{
	class VertexBufferObject
	{
		GLuint buffersID[2];

		GLfloat * datas;
		GLuint * indices;

		unsigned int indicesLength;

	public:

		VertexBufferObject() = default;
		VertexBufferObject(GLfloat * datas, unsigned int datasLength, GLuint * indices, unsigned int indicesLength);
		~VertexBufferObject();

		void Bind();
		void Draw();
	};
}