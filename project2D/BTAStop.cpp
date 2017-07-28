#include "BTAStop.h"
#include "Input.h"
#include "Entity.h"
using namespace aie;

BTAStop::BTAStop()
{
}

BTAStop::~BTAStop()
{
}

EBehaviourResult BTAStop::Execute(Entity* pEntity, float deltaTime)
{
	return EBHAVIOUR_SUCCESS;
}
