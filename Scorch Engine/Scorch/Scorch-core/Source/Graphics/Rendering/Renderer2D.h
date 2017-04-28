#ifndef _RENDERER2D_
#define _RENDERER2D_

#include "Renderable2D.h"

namespace Scorch
{
namespace Graphics
{
	class Renderer2D
	{
	public:
		virtual void Begin() { }
		virtual void End() { }
		virtual void Submit(const Renderable2D* renderable2D) = 0;
		virtual void Flush() = 0;
	}; // Renderer2D class
}; // Graphics namespace
}; // Scorch namespace

#endif
