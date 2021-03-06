#include "stdafx.h"
#include "VertexBufferObject.h"


namespace Engine
{
	VertexBufferObject::VertexBufferObject(GLfloat * datas, unsigned int datasLength, GLuint * indices, unsigned int indicesLength) : datas{ datas }, indices{ indices }, indicesLength{ indicesLength }
	{
		glGenBuffers(2, buffersID);

		glBindBuffer(GL_ARRAY_BUFFER, buffersID[0]);
		glBufferData(GL_ARRAY_BUFFER, sizeof(this->datas) * datasLength, this->datas, GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffersID[1]);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(this->indices) * indicesLength, this->indices, GL_STATIC_DRAW);
	}

	void VertexBufferObject::Bind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, buffersID[0]);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffersID[1]);
	}

	void VertexBufferObject::Draw()
	{
		glBindBuffer(GL_ARRAY_BUFFER, buffersID[0]);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffersID[1]);
		glDrawElements(GL_TRIANGLES, indicesLength, GL_UNSIGNED_INT, 0);
	}

	VertexBufferObject::~VertexBufferObject()
	{
		glDeleteBuffers(2, buffersID);
	}
}