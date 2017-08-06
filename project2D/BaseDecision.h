// #include, using, etc
#pragma once

// forward declarations
class Entity;

//--------------------------------------------------------------------------------------
// BaseDecision object.
//--------------------------------------------------------------------------------------
class BaseDecision 
{
public:

	//--------------------------------------------------------------------------------------
	// Default Constructor.
	//--------------------------------------------------------------------------------------
	BaseDecision() {};

	//--------------------------------------------------------------------------------------
	// Virtual Default Destructor
	//--------------------------------------------------------------------------------------
	virtual ~BaseDecision() {};

	//--------------------------------------------------------------------------------------
	// MakeDecision: A virtual function to update objects over time.
	//
	// Param:
	//		deltaTime: Pass in deltaTime. A number that updates per second.
	//		pEntity: a pointer to the entity.
	//--------------------------------------------------------------------------------------
	virtual void MakeDecision(Entity* pEntity, float deltaTime) = 0;
};