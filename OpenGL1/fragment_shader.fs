#version 330 core

in vec3 color;
in vec2 texture_coord;
out vec4 col;

uniform float color_offset;
uniform sampler2D texture_image;

void main(void)
{
	//col = vec4(color+color_offset, 1.0f);
	col = texture(texture_image, texture_coord)*vec4(color+color_offset, 1.0f);
}