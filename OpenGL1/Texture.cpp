#include "Texture.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"


Texture::Texture(){}
Texture::~Texture() {}

GLuint Texture::Create(const char* texture_name)
{
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	data = stbi_load(texture_name, &width, &height, &channel_nr, 0);
	if (!data)
	{
		std::cout << "Image coundn't be loaded " << std::endl;
		stbi_image_free(data);
		return 0;
	}
	else
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
		return texture;
	}
	
	

}

