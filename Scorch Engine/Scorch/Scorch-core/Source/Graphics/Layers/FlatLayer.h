#pragma once

#include "Layer.h"

namespace Scorch
{
namespace Graphics
{
	class FlatLayer: public Layer
	{
	public:
		FlatLayer(Shader* shader);
		~FlatLayer();
	};
}
}