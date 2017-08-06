// #includes, using, etc
#pragma once
#include "BTBaseNode.h"
#include <iostream>
#include "DynamicArray.h"
using namespace std;

// forward declarations
class IBehaviour;

//--------------------------------------------------------------------------------------
// BTAObAv object. Inheritance from BTBaseNode. Anwser.
//--------------------------------------------------------------------------------------
class BTAObAv : public BTBaseNode
{
public:

	//--------------------------------------------------------------------------------------
	// Default Constructor.
	//--------------------------------------------------------------------------------------
	BTAObAv();

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	~BTAObAv();

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

private:

	//--------------------------------------------------------------------------------------
	// A DynamicArray of IBehaviour pointers.
	//--------------------------------------------------------------------------------------
	DynamicArray<IBehaviour*> m_behaviours;
};