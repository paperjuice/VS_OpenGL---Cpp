#ifndef INIT_H
#define INIT_H

#include <SDL.h>
#include <GL\glew.h>
#include <SDL_opengl.h>

class Init {
public:
	Init();
	~Init();
	SDL_Window* Initialize(const GLchar* title, const GLint& x_pos, const GLint& y_pos, const GLuint WIDTH, const GLuint HEIGHT, const Uint32& flag);


private:
	SDL_Window* window;

};



#endif
