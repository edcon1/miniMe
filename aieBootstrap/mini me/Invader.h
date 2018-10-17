#pragma once
#include "vector3.h"
#include "mini_meApp.h"
#include "Application.h"
#include "Renderer2D.h"
#include <imgui.h>
#include "pathFinder.h"


class enemy
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
		m_texture = texture;
	}

	aie::Texture* getTexture()
	{
		return m_texture;
	}

private:
	Vector3 m_position;
	aie::Texture*  m_texture;
};


class AI
{
public:

	

private:

};

class seek
{
public:
	/*
	v = normalise(manPos.x - manPos.y) * maxVelocity;
	force = v - currentVelocity;*/

	void update()
{
 
}

	void setTargetPosition(Vector3 position);

private:
	Vector3 m_targetPosition;
};

