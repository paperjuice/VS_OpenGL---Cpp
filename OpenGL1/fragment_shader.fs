#version 330 core

in vec3 color;
out vec4 col;

uniform float color_offset;

void main(void)
{
	col = vec4(color+color_offset, 1.0f);
}