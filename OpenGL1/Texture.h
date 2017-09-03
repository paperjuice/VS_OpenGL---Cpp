#ifndef TEXTURE_H
#define TEXTURE_H

#include <iostream>
#include <GL/glew.h>
#include <SDL.h>
#include <SDL_opengl.h>



class Texture {
public:
	Texture();
	~Texture();
	GLuint Create(const char* texture_name);

private:
	GLint width, height, channel_nr;
	unsigned char* data;
	GLuint texture;
};




#endif