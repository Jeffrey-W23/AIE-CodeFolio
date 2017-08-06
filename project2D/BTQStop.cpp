// #includes, using, etc
#include "BTQStop.h"
#include "Entity.h"
#include "BehaviourEntity.h"

//--------------------------------------------------------------------------------------
// Default Constructor.
//--------------------------------------------------------------------------------------
BTQStop::BTQStop()
{
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
BTQStop::~BTQStop()
{

}

//--------------------------------------------------------------------------------------
// Execute: A virtual function to update objects over time.
//
// Returns:
//		EBehaviourResult: An enum of success, fail or pending.
// Param:
//		deltaTime: Pass in deltaTime. A number that updates per second.
//		pEntity: A pointer to an entity.
//--------------------------------------------------------------------------------------
EBehaviourResult BTQStop::Execute(Entity* pEntity, float deltaTime)
{
	// Check if the behaviours are stopped or not.
	if (((BehaviourEntity*)pEntity)->m_eBehType == EBEHAVIOURTYPE_STOP)
	{
		return EBHAVIOUR_SUCCESS;
	}
	else if (((BehaviourEntity*)pEntity)->m_eBehType != EBEHAVIOURTYPE_STOP)
	{
		return EBHAVIOUR_FAILURE;
	}
}