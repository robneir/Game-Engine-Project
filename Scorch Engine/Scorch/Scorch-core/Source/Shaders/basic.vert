#version 330 core

layout(location = 0) in vec4 position;

uniform mat4 m_projMatrix;
uniform mat4 m_viewMatrix = mat4(1.0);
uniform mat4 m_modelMatrix = mat4(1.0);

out vec4 pos;

void main()
{
	gl_Position = m_projMatrix * m_viewMatrix * m_modelMatrix * position; 
	pos = position;
}