#include "space_invaders_2_0App.h"
#include "Invader.h"



int main() 
{
	
	

	// allocation
	auto app = new space_invaders_2_0App();
	
	


	// initialise and loop
	app->run("AIE", 1280, 720, false);

	


	// deallocation
	delete app;

	return 0;
}