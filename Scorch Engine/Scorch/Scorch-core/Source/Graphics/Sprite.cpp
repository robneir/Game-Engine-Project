#include "Sprite.h"


namespace Scorch
{
namespace Graphics
{
	Sprite::Sprite(float x, float y, float width, float height, Vector4& color)
		: Renderable2D(Vector3(x, y, 0), Vector2(width, height), color)
	{

	}
}; // Graphics namespace
}; // Scorch namespace
