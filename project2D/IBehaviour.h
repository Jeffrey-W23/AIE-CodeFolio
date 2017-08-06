// #include, using, etc
#pragma once
#include "Vector2.h"

// forward declarations
class Entity;

//--------------------------------------------------------------------------------------
// IBehaviour object.
//--------------------------------------------------------------------------------------
class IBehaviour 
{	
public:

	//--------------------------------------------------------------------------------------
	// Default Constructor. Taking in a float fWeighting.
	//--------------------------------------------------------------------------------------
	IBehaviour(float fWeighting)
	{
		m_fWeighting = fWeighting;
	}

	//--------------------------------------------------------------------------------------
	// Virtual Default Destructor
	//--------------------------------------------------------------------------------------
	virtual ~IBehaviour(){}

	//--------------------------------------------------------------------------------------
	// Update: A virtual function from IBehaviour to update objects over time.
	//
	// Param:
	//		deltaTime: Pass in deltaTime. A number that updates per second.
	//		pEntity: a pointer to an entity.
	//--------------------------------------------------------------------------------------
	virtual Vector2 Update(Entity* pEntity, float deltaTime) = 0;
	
	//--------------------------------------------------------------------------------------
	// A pointer to a Font m_font2.
	//--------------------------------------------------------------------------------------
	float m_fWeighting;
};