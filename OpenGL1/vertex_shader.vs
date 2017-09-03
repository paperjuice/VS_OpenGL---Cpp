#version 330 core

layout(location =0) in vec3 pos;
layout(location = 1) in vec3 vertex_color;
layout(location = 2) in vec2 in_texture_coord;

out vec3 color;
out vec2 texture_coord;

void main(void)
{
	gl_Position = vec4(pos, 1.0f);
	color = vertex_color;
	texture_coord = in_texture_coord;
}