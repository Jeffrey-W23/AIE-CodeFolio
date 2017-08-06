// #include, using, etc
#pragma once
#include "BaseDecision.h"

//--------------------------------------------------------------------------------------
// BaseAnwser object. Inheritance from BaseDecision.
//--------------------------------------------------------------------------------------
class BaseAnwser : public BaseDecision
{
public:

	//--------------------------------------------------------------------------------------
	// Default Constructor.
	//--------------------------------------------------------------------------------------
	BaseAnwser() {};

	//--------------------------------------------------------------------------------------
	// Virtual Default Destructor
	//--------------------------------------------------------------------------------------
	virtual ~BaseAnwser() {};

	//--------------------------------------------------------------------------------------
	// MakeDecision: A virtual function to update objects over time.
	//
	// Param:
	//		deltaTime: Pass in deltaTime. A number that updates per second.
	//		pEntity: a pointer to the entity.
	//--------------------------------------------------------------------------------------
	virtual void MakeDecision(Entity* pEntity, float deltaTime) = 0;
};