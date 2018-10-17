#include "AntSimApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "ant.h"


AntSimApp::AntSimApp() {

}

AntSimApp::~AntSimApp() {

}

bool AntSimApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);

	m_blueAnt = new aie::Texture("../bin/textures/blue_ant.png");
	m_redAnt = new aie::Texture("../bin/textures/red_ant.png");

	Ant* ant = new Ant(Ant::red, m_redAnt);
	ant->setVelocity({ 25, 25 });
	m_ants.push_back(ant);

	ant = new Ant(Ant::red, m_redAnt);
	ant->setPosition({ getWindowWidth(), getWindowHeight() });
	ant->setVelocity({ -25, -25 });
	m_ants.push_back(ant);
	return true;
}

void AntSimApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
}

void AntSimApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();

	for (auto* ant : m_ants)
	{
		ant->update(deltaTime);
	}
	

	
}

void AntSimApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
	
	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);
	m_2dRenderer->drawSprite(m_blueAnt, getWindowWidth(), getWindowHeight(), 0, 0);
	m_2dRenderer->drawSprite(m_redAnt, getWindowWidth() * 0.5F, getWindowHeight() * 0.5F, 0, 0);
	// done drawing sprites
	
	m_2dRenderer->end();
}