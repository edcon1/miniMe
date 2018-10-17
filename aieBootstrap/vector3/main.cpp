#include "vector3App.h"
#include <iostream>
#include "vector3.h"

int main() 
{
	
	vector3 p(10, 15, 1);
	vector3 v(5, 0, 0);

	vector3 newPosition = p + v;

	// allocation
	auto app = new vector3App();

	// initialise and loop
	app->run("AIE", 1280, 720, false);

	// deallocation
	delete app;

	return 0;
}