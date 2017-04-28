#include "FlatLayer.h"
#include "../Rendering/Batch2DRenderer.h"

namespace Scorch
{
namespace Graphics
{
	FlatLayer::FlatLayer(Shader* shader) 
		: Layer(new Batch2DRenderer, shader, 
			Math::Matrix4x4::Orthographic(-16.0f, 16.0f, -9.0f, 9.0f, -1.0f, 1.0f))
	{
	}

	FlatLayer::~FlatLayer()
	{
	}
}
}