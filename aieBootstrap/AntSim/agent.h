#pragma once
#include <glm/glm.hpp>

namespace aie
{
	class Texture;
	class Renderer2D;
};

class Agent
{
public:

	Agent(aie::Texture* texture);

	void setPosition(const glm::vec2& position);
	void setVelocity(const glm::vec2& velocity);

	glm::vec2 getPosition() const;
	glm::vec2 getVelocity() const;

	void update(float deltaTime);
	void render(aie::Renderer2D* renderer);

	void setMoveSpeed(float speed) { m_moveSpeed = speed;  }
	float getMoveSpeed() const;

private:
	void updateFacing();

	glm::mat4 m_transform;
	glm::vec2 m_velocity;

	aie::Texture* m_texture;
	class AIController* m_controller = nullptr;

	float m_moveSpeed = 50;
};