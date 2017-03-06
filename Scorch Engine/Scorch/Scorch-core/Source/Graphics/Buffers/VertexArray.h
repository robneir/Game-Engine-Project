#ifndef _VERTEX_ARRAY_
#define _VERTEX_ARRAY_

#include <GL/glew.h>
#include <vector>

#include "Buffer.h"

namespace Scorch
{
namespace Graphics
{
	class VertexArray 
	{
	private:
		GLuint m_arrayID;
		std::vector<Buffer*> m_buffers;
	public:
		VertexArray();
		virtual ~VertexArray();

		void AddBuffer(Buffer* buffer, GLuint index);
		void Bind() const;
		void Unbind() const;
	}; // VertexArray class
}; // Scorch namespace
}; // Graphics namespace

#endif