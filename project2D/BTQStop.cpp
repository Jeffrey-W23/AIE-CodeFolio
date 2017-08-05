#include "BTQStop.h"
#include "Entity.h"
#include "BehaviourEntity.h"

BTQStop::BTQStop()
{
}

BTQStop::~BTQStop()
{

}

EBehaviourResult BTQStop::Execute(Entity* pEntity, float deltaTime)
{
	if (((BehaviourEntity*)pEntity)->m_eBehType == EBEHAVIOURTYPE_STOP)
	{
		return EBHAVIOUR_SUCCESS;
	}
	else if (((BehaviourEntity*)pEntity)->m_eBehType != EBEHAVIOURTYPE_STOP)
	{
		return EBHAVIOUR_FAILURE;
	}
}