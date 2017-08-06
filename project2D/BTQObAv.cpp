// #includes, using, etc
#include "BTQObAv.h"
#include "Entity.h"
#include "BehaviourEntity.h"

//--------------------------------------------------------------------------------------
// Default Constructor.
//--------------------------------------------------------------------------------------
BTQObAv::BTQObAv()
{
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
BTQObAv::~BTQObAv()
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
EBehaviourResult BTQObAv::Execute(Entity* pEntity, float deltaTime)
{
	// Check if the behaviour has been started or not.
	if (((BehaviourEntity*)pEntity)->m_eBehType == EBEHAVIOURTYPE_OA)
	{
		return EBHAVIOUR_SUCCESS;
	}
	else if (((BehaviourEntity*)pEntity)->m_eBehType != EBEHAVIOURTYPE_OA)
	{
		return EBHAVIOUR_FAILURE;
	}
}