#version 330 core

layout (location = 0) out vec4 color;

uniform vec4 m_color;
uniform vec2 m_lightPos;

in vec4 pos;

void main()
{
	float intensity = 1.0/length(pos.xy - m_lightPos);
	color = m_color * intensity;
}