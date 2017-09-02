#include "Shader.h"


Shader::Shader() {}
Shader::~Shader() {}


GLuint Shader::Create(const GLuint& type, const GLchar* shader_source_file)
{
	std::ifstream file;
	std::stringstream temp;
	std::string temp_string;

	file.open(shader_source_file);
	temp << file.rdbuf();
	file.close();
	temp_string = temp.str();
	const GLchar* output = temp_string.c_str();

	shader_id = glCreateShader(type);
	glShaderSource(shader_id, 1, &output, NULL );
	glCompileShader(shader_id);

	glGetShaderiv(shader_id, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(shader_id, 512, NULL, log_info);
		std::cout << "Shader compilation failed: " << log_info << std::endl;
		return 0;
	}
	else
	{
		return shader_id;
	}
}

GLuint Shader::Link(const GLuint& vertex_shader_id,const GLuint& fragment_shader_id )
{
	GLuint program_id = glCreateProgram();
	glAttachShader(program_id, vertex_shader_id);
	glAttachShader(program_id, fragment_shader_id);
	glLinkProgram(program_id);

	glGetProgramiv(program_id, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(program_id, 512, NULL, log_info);
		std::cout << "Program failed to link: " << log_info << std::endl;
		return 0;
	}
	else
	{
		return program_id;
	}
}
