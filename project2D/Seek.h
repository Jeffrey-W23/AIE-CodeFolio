// #include, using, etc
#pragma once
#include "IBehaviour.h"

//--------------------------------------------------------------------------------------
// Seek object. Inheritance from IBehaviour.
//--------------------------------------------------------------------------------------
class Seek : public IBehaviour
{

public:

	//--------------------------------------------------------------------------------------
	// Default Constructor. Taking in a float fWeighting.
	//--------------------------------------------------------------------------------------
	Seek(float fWeighting);
	
	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	~Seek();

	//--------------------------------------------------------------------------------------
	// Update: A virtual function from IBehaviour to update objects over time.
	//
	// Param:
	//		deltaTime: Pass in deltaTime. A number that updates per second.
	//		pEntity: a pointer to an entity.
	//--------------------------------------------------------------------------------------
	Vector2 Update(Entity* pEntity, float deltaTime);
};

