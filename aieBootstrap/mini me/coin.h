#pragma once
#include "texture.h"
#include "Application.h"
#include "Renderer2D.h"
#include <imgui.h>
#include "vector3.h"


class coins
{
public:


	void setPosition(float positionX, float positionY)
	{
		m_position.x = positionX;
		m_position.y = positionY;
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
	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
	aie::Texture*       m_Texture;
	Vector3 randomValue;
	int coinCounter = 0;
	Vector3 m_position;

	
};