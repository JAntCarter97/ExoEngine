#include "Display.h"
#include "ExoErrors.h"
#include "Shader.h"
#include "Mesh.h"
#include "Texture.h"
#include "Transform.h"
#include "Camera.h"

#include <iostream>
#include <string>
#include <vector>

#define WIDTH 800
#define HEIGHT 600

namespace exo
{

Display::Display(int width, int height, const std::string& title) : m_window(nullptr), m_screenWidth(width), m_screenHeight(height), m_currentStatus(ExoStatus::ENGAGE), m_title(title)
{

}

Display::~Display()
{
	SDL_GL_DeleteContext(m_glContext);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

void Display::run()
{
	initAll();
	engineUpdate();

}

void Display::initAll()
{
	//Initialize SDL
	SDL_Init(SDL_INIT_EVERYTHING);

	// Sets out RGBA and buffers
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	m_window = SDL_CreateWindow(m_title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_screenWidth, m_screenHeight, SDL_WINDOW_OPENGL);
	if (m_window == nullptr)
	{
		fatalError("SDL Window could not be created!");
	}

	// Made the GL context a private member variable because I want to use it in the Display destructor
	m_glContext = SDL_GL_CreateContext(m_window);
	if (m_glContext == nullptr)
	{
		fatalError("SDL_GL context could not be created!");
	}

	GLenum status = glewInit();
	if (status != GLEW_OK)
	{
		fatalError("Failed to Initialize GLEW");
	}

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	std::printf("*** OpenGL Version: %s  ***\n", glGetString(GL_VERSION));
}

void Display::clear(float r, float g, float b, float a)
{
	glClearColor(r, g, b, a);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Display::engineUpdate()
{
	// Temp Mesh init handling !!!!!!!FACTOR THIS OUT!!!!!!!!
	//Vertex vertices[] = { Vertex(glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec2(0.0f, 0.0f)),
	//					  Vertex(glm::vec3(0.0f, 0.5f, 0.0f), glm::vec2(0.5f, 1.0f)),
	//					  Vertex(glm::vec3(0.5f, -0.5f, 0.0f), glm::vec2(1.0f, 0.0f)) };

	//unsigned int indices[] = { 0, 1, 2 };

	//Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]), indices, sizeof(indices)/sizeof(indices[0]));
	Mesh mesh2("../ExoEngine/resources/Monkey3.obj");

	// Temp Shader init handling
	Shader shader("../ExoEngine/Shaders/basicShader");
	shader.Bind();
	// Temp Texture init handling !!!!!!!FACTOR THIS OUT!!!!!!!!
	//Texture texture("Textures/Brick/bricks.jpg");
	//Texture texture("Textures/Brick/stoneWall.png");
	//Texture texture("Textures/Brick/MayanStone.png");
	Texture texture("../ExoEngine/Textures/Brick/Cobblestone.png");

	//texture.Bind();

	Camera camera(glm::vec3(0.0f, 0.0f, -2.0f), 70.0f, (float)WIDTH / (float)HEIGHT, 0.01f, 1000.0f);
	Transform transform;

	float counter = 0.0f;

	while (m_currentStatus != ExoStatus::EXIT)
	{
		clear(0.0f, 0.0f, 0.0f, 1.0f);

		float sinCounter = sinf(counter);
		float cosCounter = cosf(counter);
		
		//transform.GetPos().x = sinCounter;
		//transform.GetPos().z = cosCounter;
		//transform.GetRot().x = counter;
		//transform.GetRot().y = counter;
		//transform.GetRot().z = counter;
		transform.GetRot().y = counter;
		transform.SetScale(glm::vec3(0.5f, 0.5f, 0.5f));
		//transform.SetScale(glm::vec3(cosCounter, cosCounter, cosCounter));


		shader.Update(transform, camera);
		
		processInput();
		
		mesh2.Draw();

		SDL_GL_SwapWindow(m_window);

		counter += 0.002f;
	}
}

void Display::processInput()
{
	SDL_Event e;

	while (SDL_PollEvent(&e))
	{
		switch (e.type)
		{
			case SDL_QUIT:
				m_currentStatus = ExoStatus::EXIT;
				break;
			case SDL_MOUSEMOTION:
				break;
		}
	}

}

}