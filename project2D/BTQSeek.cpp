#include "BTQSeek.h"
#include "Entity.h"
#include "Enemy3.h"

BTQSeek::BTQSeek()
{
}

BTQSeek::~BTQSeek()
{

}

EBehaviourResult BTQSeek::Execute(Entity* pEntity, float deltaTime)
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