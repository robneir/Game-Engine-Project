#include "Batch2DRenderer.h"

namespace Scorch
{
namespace Graphics
{
	Batch2DRenderer::Batch2DRenderer()
	{
		init();
	}

	Batch2DRenderer::~Batch2DRenderer()
	{
		delete m_IBO;
		glDeleteBuffers(1, &m_VBO);
	}

	void Batch2DRenderer::init()
	{
		// create VAO
		glGenVertexArrays(1, &m_VAO);
		glGenBuffers(1, &m_VBO);
		
		// bind VAO & then VBO
		glBindVertexArray(m_VAO);
		glBindBuffer(GL_ARRAY_BUFFER, m_VBO);

		// fill VBO
		glBufferData(GL_ARRAY_BUFFER, RENDERER_BUFFER_SIZE, NULL, GL_DYNAMIC_DRAW);

		/* tell shader that the 0th set of data will be vertex data 
		and 1 will be color data for that vertex */
		glEnableVertexAttribArray(SHADER_VERTEX_INDEX);
		glEnableVertexAttribArray(SHADER_COLOR_INDEX);

		// tell GPU how to handle data
		glVertexAttribPointer(SHADER_VERTEX_INDEX, 3, GL_FLOAT, GL_FALSE, RENDERER_VERTEX_SIZE, (const GLvoid*)0);
		glVertexAttribPointer(SHADER_COLOR_INDEX, 4, GL_FLOAT, GL_FALSE, RENDERER_VERTEX_SIZE, (const GLvoid*)(3 * sizeof(GLfloat)));

		// unbind VBO
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		// create IBO
		GLushort indices[RENDERER_INDICES_SIZE];
		int offset = 0;
		for (int i = 0; i < RENDERER_INDICES_SIZE; i+=6)
		{
			// first triangle
			indices[i + 0] = 0 + offset;
			indices[i + 1] = 1 + offset;
			indices[i + 2] = 2 + offset;
			// second triangle
			indices[i + 3] = 2 + offset;
			indices[i + 4] = 3 + offset;
			indices[i + 5] = 0 + offset;

			offset += 4;
		}
		m_IBO = new IndexBuffer(indices, RENDERER_INDICES_SIZE);

		// unbind VAO
		glBindVertexArray(0);
	}

	void Batch2DRenderer::Begin()
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
		m_Buffer = (VertexData*) glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
	}

	void Batch2DRenderer::Submit(const Renderable2D* renderable2D)
	{
		const Vector3 pos = renderable2D->getPosition();
		const Vector4 color = renderable2D->getColor();
		const Vector2 size = renderable2D->getSize();

		// bottom left
		m_Buffer->m_Position = pos; 
		m_Buffer->m_Color = color;
		m_Buffer++;
		// top left
		m_Buffer->m_Position = Vector3(pos.m_x, pos.m_y + size.m_y, pos.m_z);
		m_Buffer->m_Color = color;
		m_Buffer++;
		// top right
		m_Buffer->m_Position = Vector3(pos.m_x + size.m_x, pos.m_y + size.m_y, pos.m_z);
		m_Buffer->m_Color = color;
		m_Buffer++;
		// bottom right
		m_Buffer->m_Position = Vector3(pos.m_x + size.m_x, pos.m_y, pos.m_z);
		m_Buffer->m_Color = color;
		m_Buffer++;

		m_IndexCount += 6;
	}

	void Batch2DRenderer::End()
	{
		glUnmapBuffer(GL_ARRAY_BUFFER);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	void Batch2DRenderer::Draw()
	{
		glBindVertexArray(m_VAO);
		m_IBO->Bind();

		glDrawElements(GL_TRIANGLES, m_IndexCount, GL_UNSIGNED_SHORT, NULL);

		m_IBO->Unbind();
		glBindVertexArray(0);

		m_IndexCount = 0;
	}
}
}