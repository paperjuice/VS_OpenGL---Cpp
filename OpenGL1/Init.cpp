#include "Init.h"

Init::Init() {}
Init::~Init() {
	SDL_DestroyWindow(window);
	SDL_Quit();

}

SDL_Window* Init::Initialize(const GLchar* title, const GLint& x_pos, const GLint& y_pos, const GLuint WIDTH, const GLuint HEIGHT, const Uint32& flag)
{
	SDL_Init(SDL_INIT_VIDEO);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 7);

	window = SDL_CreateWindow(title, x_pos, y_pos, WIDTH, HEIGHT, flag);
	SDL_GL_CreateContext(window);
	glewExperimental = true;
	glewInit();
	glViewport(0, 0, WIDTH, HEIGHT);
	return window;
}

