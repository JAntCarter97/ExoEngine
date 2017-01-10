#include <iostream>

#include "Display.h"

int main(int argc, char** argv)
{
	exo::Display window(800, 600, "Exo Display");
	window.run();
	
	return 0;
}
//TODO: abstract engine out and create a sandbox project to test