// #includes, using, etc
#include "BTAStop.h"
#include "Input.h"
#include "Entity.h"
using namespace aie;

//--------------------------------------------------------------------------------------
// Default Constructor.
//--------------------------------------------------------------------------------------
BTAStop::BTAStop()
{
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
BTAStop::~BTAStop()
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
EBehaviourResult BTAStop::Execute(Entity* pEntity, float deltaTime)
{
	// Return success until stop is turned off
	return EBHAVIOUR_SUCCESS;
}
