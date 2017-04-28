#include <iostream>
#include <string>

#include "Source/Graphics/Window.h"
#include "Source/Graphics/Shader.h"
#include "Source/Math/Math.h"
#include "Source/Graphics/Buffers/Buffer.h"
#include "Source/Graphics/Buffers/IndexBuffer.h"
#include "Source/Graphics/Buffers/VertexArray.h"

#include "Source/Graphics/Rendering/Simple2DRenderer.h"
#include "Source/Graphics/Rendering/Batch2DRenderer.h"
#include "Source/Graphics/StaticSprite.h"
#include "Source/Graphics/Sprite.h"

#include "Source/Utilities/Timer.h"

#include "Source/Graphics/Layers/FlatLayer.h"

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

	Timer time;
	float timer = 1.0f;
	int numFrames = 0;

	Shader* shader = new Shader("Source/Shaders/basic.vert", "Source/Shaders/basic.frag");
	FlatLayer layer1(shader);
	int numSprites = 0;
	//layer.Add(new Sprite(-4, -4, 20, 20, Vector4(0.20f, 0.6f, 0.8f, 1.0f)));
	for (float y = -9.0f; y < 9.0f; y += 0.2)
	{
		for (float x = -16.0f; x < 16.0f; x += 0.2)
		{
			numSprites++;
			layer1.Add(new Sprite(x, y, 0.18f, 0.18f, Math::Vector4(rand() % 1000 / 1000.0f, 0, 1, 1)));
		}
	}

	Shader* shader2 = new Shader("Source/Shaders/basic.vert", "Source/Shaders/basic.frag");
	FlatLayer layer2(shader2);
	layer2.Add(new Sprite(-4, -4, 2, 2, Vector4(0.20f, 0.6f, 0.8f, 1.0f)));

	while (!window.IsClosed())
	{
		Matrix4x4 mat4 = Matrix4x4::Rotation(time.GetElapsedTime() * 20.0f, Vector3(0, 0, 1));
		//mat4 = mat4 * Matrix4x4::Translation(time.GetElapsedTime() * Vector3(1, 1, 0));
		//shader.setUniformMat4("m_modelMatrix", mat4);

		window.Clear();

		double x;
		double y;
		window.getMousePosition(x, y);
		shader->Enable();
		shader->setUniformVec2("m_lightPos", Vector2((float)(x / 960.0f * 32.0f - 16.0f), (float)-(y / 540.0f * 18.0f - 9.0f)));
		shader2->Enable();
		shader2->setUniformVec2("m_lightPos", Vector2((float)(x / 960.0f * 32.0f - 16.0f), (float)-(y / 540.0f * 18.0f - 9.0f)));

		layer1.Render();
		layer2.Render();

		window.Update();

		numFrames++;
		if (time.GetElapsedTime() - timer >= 1.0f)
		{
			printf("fps %d\n", numFrames);
			printf("elapsed %f\n", time.GetElapsedTime());
			numFrames = 0;
			timer += 1.0f;
		}
	}

	//delete window;
	return 0;
}
