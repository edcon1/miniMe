#include "mini_meApp.h"
#include "Texture.h"
#include "Font.h"
#include <random>
#include <ctime>
#include <iostream>
#include "coin.h"
#include "player.h"
#include "Invader.h"
#include "input.h"
#include "pathFinder.h"

mini_meApp::mini_meApp()
{
	srand((unsigned int)time(nullptr));
}

mini_meApp::~mini_meApp() 
{

}

bool mini_meApp::startup()
{

	m_2dRenderer = new aie::Renderer2D();

	
	
	
	m_player.setPosition(getWindowWidth() * 0.5F, getWindowHeight() * 0.5f);

	m_coin.setPosition(getWindowWidth() * 0.2f, getWindowHeight() * 0.2f);

	m_enemy.setPosition(getWindowWidth() * 0.7f, getWindowHeight() * 0.7f);

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);

	//making the coin and man textures 
	m_player.setTexture(new aie::Texture("../bin/textures/realpig.png"));
	m_coin.setTexture(new aie::Texture("../bin/textures/coin.png"));
	m_enemy.setTexture(new aie::Texture("../bin/textures/invader.jpg"));
	m_topGun.setTexture(new aie::Texture("../bin/textures/bigboy.png"));


	



	return true;
}

void mini_meApp::shutdown() 
{

	delete m_font;
	delete m_2dRenderer;
}

void mini_meApp::update(float deltaTime) 
{

	//this is how the coin and the character react with eachother and what happens when they do 
	
	aie::Input* input = aie::Input::getInstance();
	    
		Vector3 coinTR = m_coin.getPosition() + Vector3(25, 25, 0);
		Vector3 coinBL = m_coin.getPosition() - Vector3(25, 25, 0);

		Vector3 manTR = m_player.getPostition() + Vector3(73, 73, 0);
		Vector3 manBL = m_player.getPostition() - Vector3(73, 73, 0);
		
		Vector3 enemyTR = m_enemy.getPosition() + Vector3(37.5f, 37.5f, 0);
		Vector3 enemyBL = m_enemy.getPosition() - Vector3(37.5f, 37.5f, 0);

		
		
		

		if (coinTR.x > manBL.x && coinTR.y > manBL.y &&
			coinBL.x < manTR.x && coinBL.y < manTR.y)
		{
			randomValueY = (float)(rand() % getWindowHeight());
			randomValueX = (float)(rand() % getWindowWidth());
			m_coin.setPosition(randomValueX, randomValueY);
			coinCounter++;
		}



		if (enemyTR.x > manBL.x && enemyTR.y > manBL.y &&
			enemyBL.x < manTR.x && enemyBL.y < manTR.y)
		{
			m_isTouching = true;
		}
		else
		{
			m_isTouching = false;
			m_wasTouching = false;
		}
		if (m_isTouching == true && m_wasTouching == false)
		{
			m_wasTouching = true;
			lifeCount--;
		}

			
		
		
		
		m_player.placeInMap((float) getWindowWidth(), (float) getWindowHeight());

		m_player.update(deltaTime);

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void mini_meApp::draw()

{
	std::string finalText = "Game Over: ";

	


	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();
	 // end of game code
	if (lifeCount <= 0)
	{
		m_2dRenderer->drawText(m_font, finalText.c_str(), 0, getWindowHeight() *0.5f - m_font->getStringHeight(finalText.c_str()));
	}
	else
	{

		Vector3 a;
		Vector3 b;


		// output some text, uses the last used colour
		m_2dRenderer->drawSprite(m_player.getTexture(), m_player.getPostition().x, m_player.getPostition().y, 150, 150);
		m_2dRenderer->drawSprite(m_coin.getTexture(), m_coin.getPosition().x, m_coin.getPosition().y, 50, 50);
		m_2dRenderer->drawSprite(m_enemy.getTexture(), m_enemy.getPosition().x, m_enemy.getPosition().y, 100, 100, 0, 1);
		m_2dRenderer->drawSprite(m_topGun.getTexture(), m_topGun.getPosition().x, m_topGun.getPosition().y, -1, -1);
		m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);


		std::string coinText = "Coin Collected: ";
		coinText += std::to_string(coinCounter);

		std::string lifeText = "Life Count: ";
		lifeText += std::to_string(lifeCount);

		m_2dRenderer->drawText(m_font, lifeText.c_str(), 0, getWindowHeight() - m_font->getStringHeight(lifeText.c_str()));
		m_2dRenderer->drawText(m_font, coinText.c_str(), 0, getWindowHeight() - 2 * m_font->getStringHeight(coinText.c_str()) - 10);
		//out putting the amount of coins collected to the game 

	}
	// draw your stuff here!
	

	m_2dRenderer->end();

}