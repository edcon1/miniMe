#include "transformation_matrixApp.h"
#include "vector3.h"

int main() {
	
	// allocation
	auto app = new transformation_matrixApp();

	
	// initialise and loop
	app->run("AIE", 1280, 720, false);

	// deallocation
	delete app;

	return 0;
}