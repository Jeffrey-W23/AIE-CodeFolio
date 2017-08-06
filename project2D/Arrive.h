// #include, using, etc
#pragma once
#include "IBehaviour.h"

//--------------------------------------------------------------------------------------
// Enum EDeceleration. Used for the arrive speed.
//--------------------------------------------------------------------------------------
enum EDeceleration
{
	EDECELERATION_SLOW = 3,
	EDECELERATION_NORMAL = 2,
	EDECELERATION_FAST = 1
};

//--------------------------------------------------------------------------------------
// Arrive object. Inheritance from IBehaviour.
//--------------------------------------------------------------------------------------
class Arrive : public IBehaviour
{
public:
	
	//--------------------------------------------------------------------------------------
	// Default Constructor. Taking in a float fWeighting.
	//--------------------------------------------------------------------------------------
	Arrive(float fWeighting, EDeceleration eDeceleration);
	
	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	~Arrive();

	//--------------------------------------------------------------------------------------
	// Update: A virtual function from IBehaviour to update objects over time.
	//
	// Param:
	//		deltaTime: Pass in deltaTime. A number that updates per second.
	//		pEntity: a pointer to an entity.
	//--------------------------------------------------------------------------------------
	Vector2 Update(Entity* pEntity, float deltaTime);

private:
	
	//--------------------------------------------------------------------------------------
	// m_eDeceleration an enum of EDeceleration.
	//--------------------------------------------------------------------------------------
	EDeceleration m_eDeceleration;
};