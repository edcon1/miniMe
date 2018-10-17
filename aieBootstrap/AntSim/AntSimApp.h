#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include <vector>
#include <glm/glm.hpp>


class ant;
class Food;

class AntSimApp : public aie::Application
{
public:

	AntSimApp();
	virtual ~AntSimApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

	Food* getFoodClosestTo(const glm::vec2& location) const;

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;

	aie::Texture*       m_redAnt;
	aie::Texture*       m_blueAnt;
	aie::Texture*       m_FoodTexture;

	std::vector<Ant*>   m_ants;

	std::vector<Food*>  m_food;

	float               m_foodTimer = 0.0f;
	const float         m_foodSpawnTimer = 1.0f;

private:
	void spawnFood();
};
