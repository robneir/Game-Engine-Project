#ifndef  _RENDERABLE_2D_
#define  _RENDERABLE_2D_ 

#include "../Buffers/Buffer.h"
#include "../Buffers/VertexArray.h"
#include "../Buffers/IndexBuffer.h"
#include "../Shader.h"
#include "../../Math/Math.h"

namespace Scorch 
{
namespace Graphics
{
	using namespace Math;

	struct VertexData
	{
		Vector3 m_Position;
		//Vector4 m_Color;
		unsigned int m_Color;
	};

	class Renderable2D
	{
	protected:
		Vector3 m_Position;
		Vector2 m_Size;
		Vector4 m_Color;

		/*VertexArray* m_VertexArray;		// VAO
		Buffer* m_VertexBuffer;			// VBO of position data
		Buffer* m_ColorBuffer;			// VBO of color data
		IndexBuffer* m_IndexBuffer;		// IBO
		Shader& m_Shader;				*/// not a shader we manage so make it reference.

	public:
		Renderable2D(Vector3 position, Vector2 size, Vector4 color) :
			m_Position(position),
			m_Size(size),
			m_Color(color)
		{

		}

		virtual ~Renderable2D() { }

		inline const Vector3 getPosition() const { return m_Position; }
		inline const Vector2 getSize() const { return m_Size; }
		inline const Vector4 getColor() const { return m_Color; }
	}; // Renderable2D class
}; // Graphics namespace
}; // Scortch namespace
#endif 

