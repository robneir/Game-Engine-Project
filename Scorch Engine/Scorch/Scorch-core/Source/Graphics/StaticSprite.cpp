#include "StaticSprite.h"


namespace Scorch
{
namespace Graphics
{
	StaticSprite::StaticSprite(float x, float y, float width, float height, Vector4& color, Shader& shader) 
		: Renderable2D(Vector3(x, y, 0), Vector2(width, height), color) ,
		m_Shader(shader)
	{
		// Vertex Array
		m_VertexArray = new VertexArray();

		// Create Buffers to be added to VAO^
		GLfloat vertices[] =
		{
			0,				0,				0,
			0,				height,			0,
			width,			height,			0,
			width,			0,				0
		};
		GLfloat colors[] =
		{
			color.m_x, color.m_y, color.m_z, color.m_w,
			color.m_x, color.m_y, color.m_z, color.m_w,
			color.m_x, color.m_y, color.m_z, color.m_w,
			color.m_x, color.m_y, color.m_z, color.m_w
		};
		// Add buffers to VAO
		m_VertexArray->AddBuffer(new Buffer(vertices, 4 * 3, 3), 0);
		m_VertexArray->AddBuffer(new Buffer(colors, 4 * 4, 4), 1);

		// Index Buffer
		GLushort indices[] = {
			0,1,2,
			2,3,0
		};
		m_IndexBuffer = new IndexBuffer(indices, 6);
	}

	StaticSprite::~StaticSprite()
	{
		delete m_VertexArray;
		delete m_IndexBuffer;
	}
}; // Graphics namespace
}; // Scorch namespace