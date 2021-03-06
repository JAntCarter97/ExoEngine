#pragma once

#include <GL/glew.h>
#include <iostream>
#include <string>

namespace exo
{

class Texture
{

public:

	Texture(const std::string& fileName);

	~Texture();

	void Bind();

private:

	GLuint m_texture;

};

}