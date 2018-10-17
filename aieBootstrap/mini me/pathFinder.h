#pragma once
#include <glm/glm.hpp>
#include <vector>
#include "player.h"
#include "mini_meApp.h"

class pathfinder
{
public:
	struct Edge;
	struct Node
	{
		glm::vec2 location;
		std::vector<Edge*> edges;
	};
	struct Edge
	{
		Node* start;
		Node* end;

		float multiplier = 1.0f;
		float getEdgeCost() const;
	};

	void setChase()
	{
		
	}

	pathfinder() = default;
	pathfinder(const pathfinder& other) = delete;
	pathfinder& operator=(const pathfinder& other) = delete;

	Node const* addNode(glm::vec2 location);
	void addEdgeBetween(pathfinder::Node const* m_selectedPathFindNode, pathfinder::Node const* node);

	void removeNode(glm::vec2 location, float maxDistance = 100.0f);
	void removeNode(Node const* node);

	Node const* getClostestNode(glm::vec2 location, float maxDistance = 100.0f);

	
	

	




private:
	std::vector<Node*> m_nodes;
};