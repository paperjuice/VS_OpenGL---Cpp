#include <iostream>
#include <GL/glew.h>
#include <SDL.h>
#include <SDL_opengl.h>
#include "Init.h"

int main(int argc, char* argv[])
{
	const GLuint WIDTH = 640;
	const GLuint HEIGHT = 400;
	SDL_Event _event;
	SDL_Window* window;
	GLboolean is_running = true;
	Init init;
	window = init.Initialize("OpenGL_VS", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_OPENGL);
	

	while (is_running)
	{
		if (SDL_PollEvent(&_event))
		{
			if (_event.key.type == SDL_KEYDOWN)
			{
				switch (_event.key.keysym.sym)
				{
				case SDLK_q:
					is_running = false;
					break;
				default:
					break;
				}
			}
		}

		glClearColor(0.15f, 0.15f, 0.15f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		

		SDL_GL_SwapWindow(window);
	}



	

	return 0;
}