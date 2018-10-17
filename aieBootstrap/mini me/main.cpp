#include "mini_meApp.h"
#include "collision.h"
int main() {


	// allocation
	auto app = new mini_meApp();

	// initialise and loop
	app->run("AIE", 1280, 720, false);

	// deallocation
	delete app;

	return 0;
}