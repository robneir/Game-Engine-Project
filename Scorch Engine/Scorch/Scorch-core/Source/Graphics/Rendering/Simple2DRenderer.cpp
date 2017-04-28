#include "Simple2DRenderer.h"

namespace Scorch
{
namespace Graphics
{
	void Simple2DRenderer::Submit(const Renderable2D* renderable2D)
	{
		m_RenderQueue.push_back((StaticSprite*)renderable2D);
	}

	void Simple2DRenderer::Flush()
	{
		while (!m_RenderQueue.empty())
		{
			const StaticSprite* sprite = m_RenderQueue.front();
			sprite->getVAO()->Bind();
			sprite->getIBO()->Bind();

			// set position of renderable.
			sprite->getShader().setUniformMat4("m_modelMatrix", Math::Matrix4x4::Translation(sprite->getPosition()));
			glDrawElements(GL_TRIANGLES, sprite->getIBO()->GetCount(), GL_UNSIGNED_SHORT, 0);

			sprite->getIBO()->Unbind();
			sprite->getVAO()->Unbind();

			m_RenderQueue.pop_front();
		}
	}
}
}