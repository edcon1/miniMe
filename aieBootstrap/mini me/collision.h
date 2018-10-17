#pragma once
#include "mini_meApp.h"
#include "vector3.h"

class AABB
{
public:
	
	void setPosition(Vector3 position)
	{
		m_position = position;
	}
	
	Vector3 getPosition() { return m_position; }
 	
	

private:

	Vector3 m_position;
	Vector3 m_extents;
};