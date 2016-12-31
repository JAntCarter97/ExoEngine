#include "Errors.h"

extern void fatalError(std::string errorString)
{
	std::cout << errorString << std::endl;
	std::cout << "Enter key to quit...\n";
	char t;
	std::cin >> t;
	SDL_Quit();
	exit(69);
}

extern void fatalShaderError(std::string errorString, std::string shaderName)
{
	std::cout << errorString << ": " << shaderName << std::endl;
	std::cout << "Enter key to quit...\n";
	char t;
	std::cin >> t;
	SDL_Quit();
	exit(69);
}

extern void fatalTextureError(std::string errorString, std::string textureName)
{
	std::cout << errorString << ": " << textureName << std::endl;
	std::cout << "Enter key to quit...\n";
	char t;
	std::cin >> t;
	SDL_Quit();
	exit(69);
}

extern void fatalMeshError(std::string errorString, std::string fileName)
{
	std::cout << errorString << ": " << fileName << std::endl;
	std::cout << "Enter key to quit...\n";
	char t;
	std::cin >> t;
	SDL_Quit();
	exit(69);
}