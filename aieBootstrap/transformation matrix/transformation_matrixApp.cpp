#include "transformation_matrixApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "GameObject.h"

transformation_matrixApp::transformation_matrixApp()
{

}

transformation_matrixApp::~transformation_matrixApp() 
{

}

bool transformation_matrixApp::startup()
{
	
	m_2dRenderer = new aie::Renderer2D();

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);

	GameObject object;
	object.setRender;


	return true;
}

void transformation_matrixApp::shutdown() 
{

	delete m_font;
	delete m_2dRenderer;
}

void transformation_matrixApp::update(float deltaTime) 
{

	// input example
	aie::Input* input = aie::Input::getInstance();

	

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void transformation_matrixApp::draw() 
{

	// wipe the screen to the background colour
	clearScreen();

	GameObject obeject;

	object.setTexture(new aie::Texture("../bin/textures/realpig.png"));

	object.setRender(new aie::Renderer2D);

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
	
	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	
	
	// done drawing sprites
	m_2dRenderer->end();
}