#pragma once
#include <iostream>
#include "Application.h"
#include "Renderer2D.h"
#include "space_invaders_2_0App.h"
#include "Texture.h"
#include "Input.h"




class invader
{
public:

	aie::Texture* m_invader;
	float posX = 0;
	float posY = 0;

	

	void draw(aie::Renderer2D* renderer2D)
	{
		for (int i = 0; i < 30; i++)
		{
			m_invader = new aie::Texture("../bin/textures/invader.jpg");
			renderer2D->drawSprite(m_invader, posX, posY, 30, 30);
			posX++;
			if (i == 11)
			{
				posX = 0;
				posY++;
			}
			else if (i == 21)
			{
				posX = 0;
				posY++;
			}
			else
			{
	
			}
		}
		
	}
	

private:


};