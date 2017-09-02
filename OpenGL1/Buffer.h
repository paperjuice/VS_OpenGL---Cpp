#ifndef BUFFER_H
#define BUFFER_H

#include <SDL.h>
#include <GL/glew.h>
#include <SDL_opengl.h>

class Buffer {
public:
	Buffer();
	~Buffer();

	GLuint Create(size_t vertex_data_size,const GLfloat* vertex_data, size_t indices_size, const GLint* indices_data);

private:
	GLuint VAO, VBO, EBO;


};
#endif