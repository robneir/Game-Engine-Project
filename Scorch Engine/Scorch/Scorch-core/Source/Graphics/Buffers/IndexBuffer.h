#ifndef _INDEX_BUFFER_
#define _INDEX_BUFFER_

#include <GL/glew.h>

namespace Scorch
{
namespace Graphics
{
	class IndexBuffer {
	private:
		GLuint m_bufferID;
		GLuint m_count;
	public:
		IndexBuffer(GLushort* data, GLsizei count);

		void Bind() const;

		void Unbind() const;

		inline GLuint GetCount() const { return m_count; }
	}; // IndexBuffer class
}; // Scorch namespace
}; // Graphics namespace

#endif
