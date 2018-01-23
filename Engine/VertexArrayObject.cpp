#include "stdafx.h"
#include "VertexArrayObject.h"

namespace Engine
{
	VertexArrayObject::VertexArrayObject()
	{
		glGenVertexArrays(1, &arrayID);
		totalIndices = 0;
	}

	void VertexArrayObject::Bind()
	{
		glBindVertexArray(arrayID);
	}

	void VertexArrayObject::Unbind()
	{
		glBindVertexArray(0);
	}

	void VertexArrayObject::AddVBO(GLfloat * datas, unsigned int datasLength, GLuint * indices, unsigned int indicesLength)
	{
		//glBindVertexArray(arrayID);
		vbos.push_back(new VertexBufferObject(datas, datasLength, indices, indicesLength));
		totalIndices += indicesLength;
		//glBindVertexArray(0);
	}

	void VertexArrayObject::Draw()
	{
		glBindVertexArray(arrayID);

		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

		glBindVertexArray(0);
	}

	VertexArrayObject::~VertexArrayObject()
	{
		for (int i = 0; i < vbos.size(); i++)
			delete vbos[i];

		glDeleteVertexArrays(1, &arrayID);
	}

}