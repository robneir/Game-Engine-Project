#ifndef _BUFFER_
#define _BUFFER_

#include <GL\glew.h>

namespace Scorch
{
namespace Graphics
{
	/* Buffers are passed to shaders on GPU to draw vertex
	data to pixels on screen. */
	class Buffer
	{
	private:
		GLuint m_bufferID;

		// how many elements of buffer make up one "thing"
		GLuint m_componentCount;

	public:
		Buffer(GLfloat* data, GLsizei count, GLuint componentCount);
		~Buffer();

		void Bind() const;
		void Unbind() const;

		inline GLuint GetComponentCount() const { return m_componentCount; }
	}; // Buffer class
}; // Scorch namespace
}; // Graphics namespace

#endif
