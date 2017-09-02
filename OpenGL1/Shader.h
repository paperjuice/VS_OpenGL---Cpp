#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>
#include <SDL.h>
#include <SDL_opengl.h>
#include <sstream>
#include <fstream>
#include <string>
#include <iostream>

class Shader {
public:
	Shader();
	~Shader();

	GLuint Create(const GLuint& type, const GLchar* shader_source_file);
	GLuint Link(const GLuint& vertex_shader_id, const GLuint& fragment_shader_id);

private:
	GLuint shader_id = 0;
	GLint success;
	GLchar log_info[512];
};



#endif
