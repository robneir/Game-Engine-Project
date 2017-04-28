#ifndef _SPRITE_
#define _SPRITE_

#include "Rendering/Renderable2D.h"

namespace Scorch
{
namespace Graphics
{
	class Sprite : public Renderable2D
	{
	public:
		Sprite(float x, float y, float width, float height, Vector4& color);
	}; // Sprite class
}; // Graphics namespace
}; // Scorch namespace


#endif _SPRITE_
