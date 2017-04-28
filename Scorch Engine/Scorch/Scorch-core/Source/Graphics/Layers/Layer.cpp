#include "Layer.h"

namespace Scorch
{
namespace Graphics
{
	Layer::Layer(Renderer2D* renderer, Shader* shader, Matrix4x4 projectionMatrix) :
		m_Renderer(renderer),
		m_Shader(shader),
		m_ProjectionMatrix(projectionMatrix)
	{
		m_Shader->Enable();
		m_Shader->setUniformMat4("m_projMatrix", m_ProjectionMatrix);
		m_Shader->Disable();
	}

	Layer::~Layer()
	{
		delete m_Shader;
		delete m_Renderer;
		for (int i = 0; i < m_Renderables.size(); i++)
		{
			delete m_Renderables[i];
		}
	}

	void Layer::Add(Renderable2D* renderable)
	{
		m_Renderables.push_back(renderable);
	}

	void Layer::Render()
	{
		m_Shader->Enable();

		m_Renderer->Begin();
		for (const Renderable2D* renderable : m_Renderables)
		{
			m_Renderer->Submit(renderable);
		}
		m_Renderer->End();

		m_Renderer->Flush();

		m_Shader->Disable();
	}
}
}