#include <iostream>
#include <string>

#include "Source/Graphics/Window.h"
#include "Source/Graphics/Shader.h"
#include "Source/Math/Math.h"
#include "Source/Graphics/Buffers/Buffer.h"
#include "Source/Graphics/Buffers/IndexBuffer.h"
#include "Source/Graphics/Buffers/VertexArray.h"

using namespace Scorch;
using namespace Graphics;
using namespace Math;
using namespace Utilities;

int main()
{
	Window window("Scorch Engine", 960, 540);
	//glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

#if 0
	GLuint vbo;
	float size = 5.0f;
	GLfloat vertices[] =
	{
		0.0f * size, 0.0f * size, 0.0f,
		0.0f * size, 1.0f * size, 0.0f,
		1.0f * size, 1.0f * size, 0.0f,
		1.0f * size, 1.0f * size, 0.0f,
		1.0f * size, 0.0f * size, 0.0f,
		0.0f * size, 0.0f * size, 0.0f,
	};
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	// transmite data to shaders
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

#else
	float size = 5.0f;
	GLfloat vertices[] =
	{
		0.0f * size, 0.0f * size, 0.0f,
		0.0f * size, 1.0f * size, 0.0f,
		1.0f * size, 1.0f * size, 0.0f,
		1.0f * size, 0.0f * size, 0.0f,
	};

	GLushort indices[] = 
	{
		0, 1, 2,
		2, 3, 0,
	};

	GLfloat colorsA[] =
	{
		0.0f , 0.0f , 1.0f, 1,
		0.0f , 1.0f , 1.0f, 1,
		0.0f , 1.0f , 0.0f, 1,
		1.0f , 0.0f , 1.0f, 1,
	};

	GLfloat colorsB[] =
	{
		1.0f , 1.0f , 0.0f,	1,
		0.0f , 1.0f , 0.0f,	1,
		1.0f , 1.0f , 0.0f,	1,
		1.0f , 0.0f , 0.0f,	1,
	};

	VertexArray sprite1;
	IndexBuffer ibo(indices, 6);

	sprite1.AddBuffer(new Buffer(vertices, 4 * 3, 3), 0);
	sprite1.AddBuffer(new Buffer(colorsA, 4 * 4, 4), 1);

	VertexArray sprite2;
	sprite2.AddBuffer(new Buffer(vertices, 4 * 3, 3), 0);
	sprite2.AddBuffer(new Buffer(colorsB, 4 * 4, 4), 1);
	
#endif


	Matrix4x4 orthoMat = Matrix4x4::Orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	Shader shader("Source/Shaders/basic.vert", "Source/Shaders/basic.frag");
	shader.Enable();
	shader.setUniformMat4("m_projMatrix", orthoMat);
	shader.setUniformVec4("m_color", Vector4(1.0f, .4f, .1f, 1.0f));

	while (!window.IsClosed())
	{
		window.Clear();
		double x;
		double y;
		window.getMousePosition(x, y);
		shader.setUniformVec2("m_lightPos", Vector2((float)(x / 960.0f * 16.0f), (float)(9.0f - y * 9.0f / 540.0f)));
#if 0
		glDrawArrays(GL_TRIANGLES, 0, 6);
#else

		sprite1.Bind();
		ibo.Bind();
		Matrix4x4 transMat = Matrix4x4::Rotation(45.0f, Vector3(0, 0, 1)) * Matrix4x4::Translation(Vector3(2, 2, 0));
		shader.setUniformMat4("m_modelMatrix", transMat);
		glDrawElements(GL_TRIANGLES, ibo.GetCount(), GL_UNSIGNED_SHORT, 0);
		ibo.Unbind();
		sprite1.Unbind();


		sprite2.Bind();
		ibo.Bind();
		Matrix4x4 transMat2 = transMat * Matrix4x4::Translation(Vector3(6, 2, 0));
		shader.setUniformMat4("m_modelMatrix", transMat2);
		glDrawElements(GL_TRIANGLES, ibo.GetCount(), GL_UNSIGNED_SHORT, 0);
		ibo.Unbind();
		sprite2.Unbind();

#endif
		window.Update();
	}

	//delete window;
	return 0;
}