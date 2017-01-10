#include "InputManager.h"


namespace exo
{

InputManager::InputManager() : m_mouseCoords(0.0f, 0.0f, 0.0f)
{

}


InputManager::~InputManager()
{

}

void InputManager::update()
{
	for (auto& it : m_keyMap)
	{
		m_previousKeyMap[it.first] = it.second;
	}
}

void InputManager::pressKey(unsigned int keyID)
{
	m_keyMap[keyID] = true;
}

void InputManager::releaseKey(unsigned int keyID)
{
	m_keyMap[keyID] = false;
}

bool InputManager::isKeyDown(unsigned int keyID)
{
	auto it = m_keyMap.find(keyID);
	if (it != m_keyMap.end())
	{
		return it->second;
	}
	else
	{
		return false;
	}
}

bool InputManager::isKeyPressed(unsigned int keyID)
{
	//TODO: only works for a key press in this particular frame
	//Add a selective timer that will work with specific object
	//used as the consequence of an input
	if (isKeyDown(keyID) == true && wasKeyDown(keyID) == false)
	{
		return true;
	}
	return false;
}

void InputManager::setMouseCoords(float x, float y, float z)
{
	m_mouseCoords.x = x;
	m_mouseCoords.y = y;
	m_mouseCoords.z = z;
}

bool InputManager::wasKeyDown(unsigned int keyID)
{
	auto it = m_previousKeyMap.find(keyID);
	if (it != m_previousKeyMap.end())
	{
		return it->second;
	}
	else
	{
		return false;
	}
}

}