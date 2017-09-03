#include <iostream>
#include <GL/glew.h>
#include <SDL.h>
#include <SDL_opengl.h>
#include "Init.h"
#include "Shader.h"
#include "Buffer.h"
#include "Texture.h"

int main(int argc, char* argv[])
{
	const GLuint WIDTH = 1024;
	const GLuint HEIGHT = 762;
	float a = 0;
	Uint32 end_time = 0;
	SDL_Event _event;
	SDL_Window* window;
	Shader sh;
	Buffer bfr;
	Texture texture;
	GLboolean is_running = true;
	Init init;
	
	const GLfloat vertex[] = {
	0.5f, -0.5f, 0.0f,        0.9f, 0.1f, 0.1f,      1.0f, 0.0f,
	-0.5f, -0.5f, 0.0f,       0.1f, 0.9f, 0.9f,       0.0f, 0.0f,
	-0.5f,  0.5f, 0.0f,       0.9f, 0.9f, 0.1f,       0.0f, 1.0f,
	0.5f, 0.5f, 0.0f,         0.9f, 0.1f, 0.9f,        1.0f, 1.0f
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
	const GLuint texture_id = texture.Create("texture.jpg");
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

		const GLuint uniform = glGetUniformLocation(program_shader, "color_offset");
		Uint32 start_time = SDL_GetTicks();
		if (start_time - end_time >= 60)
		{
			end_time = start_time;
			a+=0.05f;
		}
		glUniform1f(uniform, sin(a));


		glClearColor(0.15f, 0.15f, 0.15f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		
		glUseProgram(program_shader);
		
		glBindTexture(GL_TEXTURE_2D, texture_id);
		glBindVertexArray(VAO);

		//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glDrawElements(GL_TRIANGLES, sizeof(vertex) / sizeof(GLfloat), GL_UNSIGNED_INT, 0);
		
		glBindVertexArray(0);

		SDL_GL_SwapWindow(window);
	}

	return 0;
}