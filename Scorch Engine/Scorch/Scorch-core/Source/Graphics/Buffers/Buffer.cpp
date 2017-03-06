#include "Buffer.h"

namespace Scorch
{
namespace Graphics
{
	/* 
	data:				is pointer to start of float array
	count:				is the number of elements in array
	componentCount:		is the number of contiguous elements that make one piece of data (vertex for example).
	*/
	Buffer::Buffer(GLfloat* data, GLsizei count, GLuint componentCount):
		m_componentCount(componentCount)
	{
		glGenBuffers(1, &m_bufferID);
		glBindBuffer(GL_ARRAY_BUFFER, m_bufferID);
		glBufferData(GL_ARRAY_BUFFER, count * sizeof(GLfloat), data, GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	Buffer::~Buffer()
	{
		glDeleteBuffers(1, &m_bufferID);
	}

	void Buffer::Bind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_bufferID);
	}

	void Buffer::Unbind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

}; // Scorch namespace
}; // Graphics namespace