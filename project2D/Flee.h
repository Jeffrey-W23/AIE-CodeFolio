// #include, using, etc
#pragma once
#include "IBehaviour.h"

//--------------------------------------------------------------------------------------
// Flee object. Inheritance from IBehaviour.
//--------------------------------------------------------------------------------------
class Flee : public IBehaviour
{
public:
	
	//--------------------------------------------------------------------------------------
	// Default Constructor. Taking in a float fWeighting and a bool for mouseflee or not.
	//--------------------------------------------------------------------------------------
	Flee(float fWeighting, bool bMouseFlee);
	
	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	~Flee();

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
	// bool for if the flee point should be the mouse or not.
	//--------------------------------------------------------------------------------------
	bool m_bFleeMouse;
};

