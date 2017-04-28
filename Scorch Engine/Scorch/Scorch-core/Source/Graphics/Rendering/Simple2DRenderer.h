#ifndef _SIMPLE_2D_RENDERER_
#define _SIMPLE_2D_RENDERER_

#include <deque>

#include "Renderer2D.h"
#include "Renderable2D.h"
#include "../StaticSprite.h"

namespace Scorch
{
namespace Graphics
{
	class Simple2DRenderer: public Renderer2D
	{
	private:
		std::deque<const StaticSprite*> m_RenderQueue;
	public:
		void Submit(const Renderable2D* renderable2D) override;
		void Flush() override;
	};
}
}

#endif
