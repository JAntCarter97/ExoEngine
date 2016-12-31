#pragma once

#include <SDL/SDL.h>
#include <iostream>
#include <string>
#include <cstdlib>

extern void fatalError(std::string errorString);

extern void fatalShaderError(std::string errorString, std::string shaderName);

extern void fatalTextureError(std::string errorString, std::string textureName);

extern void fatalMeshError(std::string errorString, std::string fileName);