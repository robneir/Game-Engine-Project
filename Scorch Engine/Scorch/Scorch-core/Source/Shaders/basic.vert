#version 330 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec4 color;

uniform mat4 m_projMatrix;
uniform mat4 m_viewMatrix = mat4(1.0);
uniform mat4 m_modelMatrix = mat4(1.0);

out DATA
{
	vec4 pos;
	vec4 col;
} vs_out;

void main()
{
	gl_Position = m_projMatrix * m_viewMatrix * m_modelMatrix * position; 
	vs_out.pos = m_modelMatrix * position; // this is to make move light follow relative to screen space.
	vs_out.col = color;
}