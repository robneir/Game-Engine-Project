#include <iostream>
#include <string>

#include "Source/Graphics/Window.h"
#include "Source/Graphics/Shader.h"
#include "Source/Math/Math.h"
#include "Source/Graphics/Buffers/Buffer.h"
#include "Source/Graphics/Buffers/IndexBuffer.h"
#include "Source/Graphics/Buffers/VertexArray.h"

#include "Source/Graphics/Simple2DRenderer.h"
#include "Source/Graphics/Batch2DRenderer.h"
#include "Source/Graphics/StaticSprite.h"
#include "Source/Graphics/Sprite.h"

#include <time.h>

#define BATCH_RENDERER 1

using namespace Scorch;
using namespace Graphics;
using namespace Math;
using namespace Utilities;

int main()
{
	Window window("Scorch Engine", 960, 540);
	//glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	Matrix4x4 orthoMat = Matrix4x4::Orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);
	Shader shader("Source/Shaders/basic.vert", "Source/Shaders/basic.frag");
	shader.Enable();
	shader.setUniformMat4("m_projMatrix", orthoMat);
	shader.setUniformVec4("m_color", Vector4(1.0f, .4f, .1f, 1.0f));
	
	
	std::vector<Renderable2D*> sprites;

	srand(time(NULL));

	for (float y = 0; y < 16.0f; y+= 0.1f)
	{
		for (float x = 0; x < 16.0f; x+= 0.1f)
		{
#if BATCH_RENDERER
			sprites.push_back(new Sprite(x, y, 0.08f, 0.08f, Vector4(rand() % 1000 / 999.0f, 0, 1, 1)));
#else
			sprites.push_back(new StaticSprite(x, y, 0.08f, 0.08f, Vector4(rand() % 1000 / 999.0f, 0, 1, 1), shader));
#endif
		}
	}

#if BATCH_RENDERER
	Batch2DRenderer renderer;
#else
	Simple2DRenderer renderer;
#endif


	while (!window.IsClosed())
	{
		window.Clear();

#if BATCH_RENDERER
		renderer.Begin();
#endif
		for (int i = 0; i < sprites.size(); i++)
		{
			renderer.Submit(sprites[i]);
		}
#if BATCH_RENDERER
		renderer.End();
#endif
		renderer.Draw();

		double x;
		double y;
		window.getMousePosition(x, y);
		shader.setUniformVec2("m_lightPos", Vector2((float)(x / 960.0f * 16.0f), (float)(9.0f - y * 9.0f / 540.0f)));

		window.Update();
	}

	//delete window;
	return 0;
}
