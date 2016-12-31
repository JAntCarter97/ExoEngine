#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <iostream>
#include <string>
#include "obj_loader.h"

/********* VERTEX DATA CLASS **********/
class Vertex
{

public:

	Vertex(const glm::vec3& pos, const glm::vec2 texCoord, const glm::vec3& normal = glm::vec3(0,0,0))
	{
		this->pos = pos;
		this->texCoord = texCoord;
		this->normal = normal;
	}

	inline glm::vec3* GetPos() { return &pos; }
	inline glm::vec2* GetTexCoord() { return &texCoord; }
	inline glm::vec3* GetNormal() { return &normal; }

private:

	glm::vec3 pos;
	glm::vec2 texCoord;
	glm::vec3 normal;
};

enum
{
	POSITION_VB,
	TEXCOORD_VB,
	NORMAL_VB,
	INDEX_VB,
	NUM_BUFFERS
};

/********* MESH CLASS ***********/
class Mesh
{

public:

	Mesh(Vertex* vertices, unsigned int numVertices, unsigned int* indices, unsigned int numIndices);
	Mesh(const std::string& fileName);

	~Mesh();

	void Draw();

private:

	void InitMesh(const IndexedModel& model);



	GLuint m_vertexArrayObject;
	GLuint m_vertexArrayBuffers[NUM_BUFFERS];
	unsigned int m_drawCount;

};
