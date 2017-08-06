// #include, using, etc
#pragma once
#include "IBehaviour.h"

//--------------------------------------------------------------------------------------
// ObstacleAvoidance object. Inheritance from IBehaviour.
//--------------------------------------------------------------------------------------
class ObstacleAvoidance : public IBehaviour
{
public:
	
	//--------------------------------------------------------------------------------------
	// Default Constructor. Taking in a float fWeighting.
	//--------------------------------------------------------------------------------------
	ObstacleAvoidance(float fWeighting);
	
	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	~ObstacleAvoidance();

	//--------------------------------------------------------------------------------------
	// Update: A virtual function from IBehaviour to update objects over time.
	//
	// Param:
	//		deltaTime: Pass in deltaTime. A number that updates per second.
	//		pEntity: a pointer to an entity.
	//--------------------------------------------------------------------------------------
	Vector2 Update(Entity* pEntity, float deltaTime);

private:
};