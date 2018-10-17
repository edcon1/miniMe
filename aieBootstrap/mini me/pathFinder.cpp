#include "pathFinder.h"

float pathfinder::Edge::getEdgeCost() const
{
	float distance = glm::length(end->location - start->location);
	return distance * multiplier;
}

pathfinder::Node const* pathfinder::addNode(glm::vec2 location)
{
	return 0;
}

void pathfinder::addEdgeBetween(pathfinder::Node const * m_selectedPathFindNode, pathfinder::Node const * node)
{

}

void pathfinder::removeNode(glm::vec2 location, float maxDistance)
{

}

void pathfinder::removeNode(Node const * node)
{

}


