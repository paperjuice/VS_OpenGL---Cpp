#include <iostream>
#include <GL/glew.h>
#include <SDL.h>
#include <SDL_opengl.h>
#include "Init.h"
#include "Shader.h"
#include "Buffer.h"

int main(int argc, char* argv[])
{
	const GLuint WIDTH = 640;
	const GLuint HEIGHT = 400;
	SDL_Event _event;
	SDL_Window* window;
	Shader sh;
	Buffer bfr;
	GLboolean is_running = true;
	Init init;
	
	const GLfloat vertex[] = {
	0.5f, -0.5f, 0.0f,
	-0.5f, -0.5f, 0.0f,
	-0.5f,  0.5f, 0.0f,
	0.5f, 0.5f, 0.0f
	};
	const size_t vertex_size = sizeof(vertex);

	const GLint indeces[] = {
	0, 1, 2,
	0, 2, 3
	};


	window = init.Initialize("OpenGL_VS", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_OPENGL);
	const GLuint vertex_shader = sh.Create(GL_VERTEX_SHADER, "vertex_shader.vs");
	const GLuint fragment_shader = sh.Create(GL_FRAGMENT_SHADER, "fragment_shader.fs");
	const GLuint program_shader = sh.Link(vertex_shader, fragment_shader);

	const GLuint VAO = bfr.Create(vertex_size, vertex, sizeof(indeces), indeces);

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
		
		glUseProgram(program_shader);
		
		glBindVertexArray(VAO);

		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glDrawElements(GL_TRIANGLES, sizeof(vertex) / sizeof(GLfloat), GL_UNSIGNED_INT, 0);
		
		glBindVertexArray(0);

		

		SDL_GL_SwapWindow(window);
	}



	

	return 0;
}