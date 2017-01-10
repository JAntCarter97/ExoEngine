#include <iostream>

#include "Display.h"

int main(int argc, char** argv)
{
	exo::Display window(800, 600, "Exo Display");
	window.run();
	
	return 0;
}
