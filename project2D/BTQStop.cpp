#include "BTQStop.h"
#include "Entity.h"
#include "Enemy3.h"

BTQStop::BTQStop()
{
}

BTQStop::~BTQStop()
{

}

EBehaviourResult BTQStop::Execute(Entity* pEntity, float deltaTime)
{
	if (((Enemy3*)pEntity)->m_eBehType == EBEHAVIOURTYPE_STOP)
	{
		return EBHAVIOUR_SUCCESS;
	}
	else if (((Enemy3*)pEntity)->m_eBehType != EBEHAVIOURTYPE_STOP)
	{
		return EBHAVIOUR_FAILURE;
	}
}