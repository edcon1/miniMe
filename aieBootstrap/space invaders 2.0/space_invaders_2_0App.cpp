#include "space_invaders_2_0App.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include <random>
#include <ctime>
#include <iostream>
#include "Invader.h"


space_invaders_2_0App::space_invaders_2_0App() 
{

}

space_invaders_2_0App::~space_invaders_2_0App() 
{

}

bool space_invaders_2_0App::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);

	//making the textures
	m_invader = new aie::Texture("../bin/textures/invader.jpg");
	m_ship = new aie::Texture("../bin/textures/Space-invaders.jpg");
	m_sheild = new aie::Texture("../bin/textures/sheild.png");

	return true;
}

void space_invaders_2_0App::shutdown() {

	delete m_font;
	delete m_2dRenderer;
}

void space_invaders_2_0App::update(float deltaTime) 
{
	invader fred;

	// input example
	aie::Input* input = aie::Input::getInstance();

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}


void space_invaders_2_0App::draw()
{ 

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
	

	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}