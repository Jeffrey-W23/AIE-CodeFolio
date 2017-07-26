#pragma once
#include "Vector2.h"

class Entity;

class IBehaviour {
	
public:

	IBehaviour(float fWeighting)
	{
		m_fWeighting = fWeighting;
	}

	~IBehaviour(){}

	virtual Vector2 Update(Entity* pEntity, float deltaTime) = 0;
	
	float m_fWeighting;
};