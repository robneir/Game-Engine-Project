#version 330 core

layout (location = 0) out vec4 color;

uniform vec4 m_color;
uniform vec2 m_lightPos;

in DATA
{
	vec4 pos;
	vec4 col;
} fs_in;

void main()
{
	float intensity = 1.0/length(fs_in.pos.xy - m_lightPos);
	//color = m_color * intensity;
	color = fs_in.col * intensity;
}