// #includes, using, etc
#pragma once
#include "BTBaseNode.h"
#include <iostream>
using namespace std;

//--------------------------------------------------------------------------------------
// BTAStop object. Inheritance from BTBaseNode. Anwser.
//--------------------------------------------------------------------------------------
class BTAStop : public BTBaseNode
{
public:

	//--------------------------------------------------------------------------------------
	// Default Constructor.
	//--------------------------------------------------------------------------------------
	BTAStop();

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	~BTAStop();

	//--------------------------------------------------------------------------------------
	// Execute: A virtual function to update objects over time.
	//
	// Returns:
	//		EBehaviourResult: An enum of success, fail or pending.
	// Param:
	//		deltaTime: Pass in deltaTime. A number that updates per second.
	//		pEntity: A pointer to an entity.
	//--------------------------------------------------------------------------------------
	EBehaviourResult Execute(Entity* pEntity, float deltaTime);
};