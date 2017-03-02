#include <iostream>
#include <string>

#include "Source/Graphics/Window.h"
#include "Source/Graphics/Shader.h"
#include "Source/Math/Math.h"

using namespace Scorch;
using namespace Graphics;
using namespace Math;
using namespace Utilities;

int main()
{
	Window window("Scorch Engine", 960, 540);
	//glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

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

	Matrix4x4 orthoMat = Matrix4x4::Orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	Shader shader("Source/Shaders/basic.vert", "Source/Shaders/basic.frag");
	shader.Enable();
	shader.setUniformMat4("m_projMatrix", orthoMat);

	Matrix4x4 transMat = Matrix4x4::Rotation(45.0f, Vector3(0, 0, 1)) * Matrix4x4::Translation(Vector3(2, 2, 0));
	shader.setUniformMat4("m_modelMatrix", transMat);
	shader.setUniformVec2("m_lightPos", Vector2(2.5f, 2.5f));
	shader.setUniformVec4("m_color", Vector4(1.0f, .4f, .1f, 1.0f));

	while (!window.IsClosed())
	{
		window.Clear();
		glDrawArrays(GL_TRIANGLES, 0, 6);
		window.Update();
	}

	//delete window;
	return 0;
}