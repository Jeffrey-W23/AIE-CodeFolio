#pragma once
#include "IBehaviour.h"

class ObstacleAvoidance : public IBehaviour
{
public:
	ObstacleAvoidance(float fWeighting);
	~ObstacleAvoidance();

	Vector2 Update(Entity* pEntity, float deltaTime);

private:

};