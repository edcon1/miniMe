#pragma once
#include "agent.h"

namespace aie { class Application; };
class Ant : public Agent
{
public:
	enum Team
	{
		red,
		blue
	};
	

	void giveFood() { m_hasFood = true; }
	void dropFood() { m_hasFood = false; }

	
private:

	Team m_team;
	bool m_hasFood = false;
};