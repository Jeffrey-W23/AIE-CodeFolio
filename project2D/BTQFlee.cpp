#include "BTQFlee.h"
#include "Entity.h"
#include "Enemy3.h"

BTQFlee::BTQFlee()
{
}

BTQFlee::~BTQFlee()
{

}

EBehaviourResult BTQFlee::Execute(Entity* pEntity, float deltaTime)
{
	if (((Enemy3*)pEntity)->m_eBehType == EBEHAVIOURTYPE_SEEK)
	{
		return EBHAVIOUR_SUCCESS;
	}
	else if (((Enemy3*)pEntity)->m_eBehType != EBEHAVIOURTYPE_SEEK)
	{
		return EBHAVIOUR_FAILURE;
	}
}