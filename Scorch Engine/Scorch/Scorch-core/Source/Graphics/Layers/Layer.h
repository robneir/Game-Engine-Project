#pragma once

#include "../Rendering/Renderer2D.h"
#include "../Rendering/Renderable2D.h"

namespace Scorch
{
namespace Graphics
{
	class Layer 
	{
	protected:
		Renderer2D* m_Renderer;
		std::vector<Renderable2D*> m_Renderables;
		Shader* m_Shader;
		Matrix4x4 m_ProjectionMatrix;
	protected:
		Layer(Renderer2D* renderer, Shader* shader, Matrix4x4 projectionMatrix);
	public:
		virtual ~Layer();
		virtual void Add(Renderable2D* renderable);
		virtual void Render();
	};
}
}