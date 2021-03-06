// #includes, using, etc
#pragma once
#include "BTBaseNode.h"
#include "Input.h"
#include <iostream>
using namespace std;
using namespace aie;

//--------------------------------------------------------------------------------------
// BTQStop object. Inheritance from BTBaseNode. Question.
//--------------------------------------------------------------------------------------
class BTQStop : public BTBaseNode
{
public:

	//--------------------------------------------------------------------------------------
	// Default Constructor.
	//--------------------------------------------------------------------------------------
	BTQStop();

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	~BTQStop();

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