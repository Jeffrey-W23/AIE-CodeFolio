#include "BTQFlee.h"

BTQFlee::BTQFlee()
{
	m_bBehaviour = false;
}

BTQFlee::~BTQFlee()
{

}

EBehaviourResult BTQFlee::Execute(Entity* pEntity, float deltaTime)
{
	if (Input::getInstance()->wasKeyPressed(INPUT_KEY_F))
	{
		m_bBehaviour = true;
	}
	else
	{
		m_bBehaviour = false;
	}

	if (m_bBehaviour)
	{
		return EBHAVIOUR_SUCCESS;
	}
	else
	{
		return EBHAVIOUR_FAILURE;
	}
}