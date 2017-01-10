#pragma once
#include <glm/glm.hpp>
#include <unordered_map>

namespace exo
{

class InputManager
{
public:

	InputManager();
	
	~InputManager();

	void update();

	void pressKey(unsigned int keyID);

	void releaseKey(unsigned int keyID);

	// Returns true if key is pressed
	bool isKeyDown(unsigned int keyID);

	// Returns true if key was just pressed (for one frame: for now)
	bool isKeyPressed(unsigned int keyID);

	// Setters
	void setMouseCoords(float x, float y, float z);

	// Getters
	glm::vec3 getMouseCoords() const { return m_mouseCoords; }

private:
	// Returns true if key was just down
	bool wasKeyDown(unsigned int keyID);

	glm::vec3 m_mouseCoords;

	std::unordered_map<unsigned int, bool> m_keyMap;
	std::unordered_map<unsigned int, bool> m_previousKeyMap;

};

}