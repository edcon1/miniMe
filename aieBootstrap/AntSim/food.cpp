#include "food.h"
#include "Renderer2D.h"

Food::Food(glm::vec2 position, aie::Texture* texture)
{
	m_position = position;
	m_texture = texture;
}
void Food::render(aie::Renderer2D* renderer) const
{
	renderer->drawSprite(m_texture, m_position.x, m_position.y, 32, 32);
}
glm::vec2 Food::getPosition() const
{
	return m_position;
}