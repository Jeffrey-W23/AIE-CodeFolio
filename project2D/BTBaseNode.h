// #includes, using, etc
#pragma once

// forward declarations
class Entity;

//--------------------------------------------------------------------------------------
// Enum EBehaviourResult. Used for telling if a node as passed or not.
//--------------------------------------------------------------------------------------
enum EBehaviourResult
{
	EBHAVIOUR_FAILURE,
	EBHAVIOUR_SUCCESS,
	EBHAVIOUR_PENDING
};

//--------------------------------------------------------------------------------------
// BTBaseNode object.
//--------------------------------------------------------------------------------------
class BTBaseNode
{
public:

	//--------------------------------------------------------------------------------------
	// Default Constructor.
	//--------------------------------------------------------------------------------------
	BTBaseNode() {};

	//--------------------------------------------------------------------------------------
	// Virtual Default Destructor
	//--------------------------------------------------------------------------------------
	virtual ~BTBaseNode() {};

	//--------------------------------------------------------------------------------------
	// Execute: A virtual function to update objects over time.
	//
	// Returns:
	//		EBehaviourResult: An enum of success, fail or pending.
	// Param:
	//		deltaTime: Pass in deltaTime. A number that updates per second.
	//		pEntity: A pointer to an entity.
	//--------------------------------------------------------------------------------------
	virtual EBehaviourResult Execute(Entity* pEntity, float deltaTime) = 0;
};