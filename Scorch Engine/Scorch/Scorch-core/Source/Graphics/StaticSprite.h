#ifndef _STATIC_SPRITE_
#define _STATIC_SPRITE_

#include "Renderable2D.h"
#include "../Math/Vector4.h"

namespace Scorch
{
namespace Graphics
{
	class StaticSprite : public Renderable2D
	{
	private:
		VertexArray* m_VertexArray;		// VAO
		Buffer* m_VertexBuffer;			// VBO of position data
		Buffer* m_ColorBuffer;			// VBO of color data
		IndexBuffer* m_IndexBuffer;		// IBO
		Shader& m_Shader;				// not a shader we manage so make it reference.
	public:
		StaticSprite(float x, float y, float width, float height, Vector4& color, Shader& shader);
		~StaticSprite();

		inline Shader& getShader() const { return m_Shader; }
		inline const VertexArray* getVAO() const { return m_VertexArray; }
		inline const IndexBuffer* getIBO() const { return m_IndexBuffer; }
	}; // StaticSprite class
}; // Graphics namespace
}; // Scorch namespace


#endif _STATIC_SPRITE_
