#pragma once

#include <SDL/SDL.h>
#include <GL/glew.h>
#include <string>

namespace exo
{

// Used in Poll Events in processInput()
enum class ExoStatus { ENGAGE, EXIT };

class Display
{
public:

	Display(int width, int height, const std::string& title);
	~Display();

	void run();


private:
	
	void initAll();
	void engineUpdate();
	void processInput();
	void clear(float r, float g, float b, float a);

	SDL_Window* m_window;
	std::string m_title;
	int m_screenWidth;
	int m_screenHeight;
	ExoStatus m_currentStatus;
	SDL_GLContext m_glContext;
};

}