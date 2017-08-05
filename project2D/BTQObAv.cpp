#include "BTQObAv.h"
#include "Entity.h"
#include "BehaviourEntity.h"

BTQObAv::BTQObAv()
{
}

BTQObAv::~BTQObAv()
{

}

EBehaviourResult BTQObAv::Execute(Entity* pEntity, float deltaTime)
{
	if (((BehaviourEntity*)pEntity)->m_eBehType == EBEHAVIOURTYPE_OA)
	{
		return EBHAVIOUR_SUCCESS;
	}
	else if (((BehaviourEntity*)pEntity)->m_eBehType != EBEHAVIOURTYPE_OA)
	{
		return EBHAVIOUR_FAILURE;
	}
}