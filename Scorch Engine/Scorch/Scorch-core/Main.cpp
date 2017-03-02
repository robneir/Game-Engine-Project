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
	glClearColor(0, 0.4f, 1.0f, 1.0f);

	GLuint vbo;
	GLfloat vertices[] =
	{
		-0.2f, -0.2f, 0.0f,
		-0.2f,  0.2f, 0.0f,
		 0.2f,  0.2f, 0.0f,
		 0.2f,  0.2f, 0.0f,
		 0.2f, -0.2f, 0.0f,
		-0.2f, -0.2f, 0.0f,
	};
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	// transmite data to shaders
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

	Shader shader("Source/Shaders/basic.vert", "Source/Shaders/basic.frag");
	shader.Enable();

	while (!window.IsClosed())
	{
		window.Clear();
		glDrawArrays(GL_TRIANGLES, 0, 6);
		window.Update();
	}

	//delete window;
	return 0;
}