#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include <imgui.h>
#include "vector3.h"
#include "coin.h"
#include "Invader.h"
#include "player.h"


class mini_meApp : public aie::Application 
{
public:

	mini_meApp();
	virtual ~mini_meApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
	
	player m_player;
	coins m_coin;
	enemy m_enemy;
	enemy m_enemy2;
	enemy m_enemy3;
	enemy m_enemy4;
	gun m_topGun;
	
	
	
	Vector3 randomValue;
	int coinCounter = 0;
	float randomValueX = 0;
	float randomValueY = 0;
	void randomCoin();
	int lifeCount = 10;
	bool m_isTouching = false;
	bool m_wasTouching = false;

};