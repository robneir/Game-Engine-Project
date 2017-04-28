#ifndef _BATCH_2D_RENDERER_
#define _BATCH_2D_RENDERER_

#include <cstddef>

#include "Renderer2D.h"
#include "../Buffers/IndexBuffer.h"


namespace Scorch
{
namespace Graphics
{
#define RENDERER_MAX_SPRITES		60000
#define RENDERER_VERTEX_SIZE		sizeof(VertexData)
#define RENDERER_SPRITE_SIZE		RENDERER_VERTEX_SIZE * 4
#define RENDERER_BUFFER_SIZE		RENDERER_SPRITE_SIZE * RENDERER_MAX_SPRITES
#define RENDERER_INDICES_SIZE		RENDERER_MAX_SPRITES * 6

#define SHADER_VERTEX_INDEX 0
#define SHADER_COLOR_INDEX 1

	class Batch2DRenderer : public Renderer2D
	{
	private:
		GLuint m_VAO;
		IndexBuffer* m_IBO;
		GLsizei m_IndexCount;
		GLuint m_VBO;
		VertexData* m_Buffer;
	public:
		Batch2DRenderer();
		~Batch2DRenderer();
		void Begin() override;
		void End() override;
		void Submit(const Renderable2D* renderable2D) override;
		void Flush() override;
	private:
		void init();
	};
};
};

#endif
