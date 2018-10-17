#pragma once
#include "texture.h"
#include "input.h"
#include "vector3.h"
#include "Application.h"
#include "Renderer2D.h"
#include <imgui.h>
#include "matrix3.h"

class player
{
public:

	void update(float delta_time)
	{
		// identify's input for next code
		aie::Input* input = aie::Input::getInstance();

		// code for the character to move with input keys
		if (input->isKeyDown(aie::INPUT_KEY_W) || input->isKeyDown(aie::INPUT_KEY_UP))
		{
			m_position.y += 0.3f;
		}

		if (input->isKeyDown(aie::INPUT_KEY_S) || input->isKeyDown(aie::INPUT_KEY_DOWN))
		{
			m_position.y -= 0.3f;
		}

		if (input->isKeyDown(aie::INPUT_KEY_A) || input->isKeyDown(aie::INPUT_KEY_LEFT))
		{
			m_position.x -= 0.3f;
		}
		if (input->isKeyDown(aie::INPUT_KEY_D) || input->isKeyDown(aie::INPUT_KEY_RIGHT))
		{
			m_position.x += 0.3f;
		}
	}

	bool isInsideWall(float windowWidth, float windowHeight)
	{
		if (m_position.x < 0 || m_position.x > windowWidth || m_position.y < 0 || m_position.y > windowHeight)
		{
			return false;
		}
		return true;
		
		
	}

	void placeInMap(float windowWidth, float windowHeight)
	{
		if (isInsideWall(windowWidth, windowHeight) == false)
		{
			if (m_position.x < 0)
			{
				m_position.x = windowWidth;
			}
			if (m_position.y < 0)
			{
				m_position.y = windowHeight;
			}
			if (m_position.x > windowWidth)
			{
				m_position.x = 0;
			}
			if (m_position.y > windowHeight)
			{
				m_position.y = 0;
			}
		}
	}

	void setPosition(float positionX, float positionY)
	{
		m_position.x = positionX;
		m_position.y = positionY;
	}

	Vector3 getPostition() const
	{
		return m_position;
	}

	void setTexture(aie::Texture* texture)
	{
		m_texture = texture;
	}

	aie::Texture* getTexture()
	{
		return m_texture;
	}

private:
	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
	aie::Texture*       m_texture;
	Vector3 m_position;
};

class gun
{
public:

	void setPosition(float positionX, float positionY)
	{
		m_topGun.x = positionX;
		m_topGun.y = positionY;
	}

	Vector3 getPosition() const
	{
		return m_position;
	}

	void setTexture(aie::Texture* texture)
	{
		m_Texture = texture;
	}

	aie::Texture* getTexture()
	{
		return m_Texture;
	}



private:
	Vector3 m_topGun;
	aie::Texture* m_Texture;
	Vector3 m_position;
};