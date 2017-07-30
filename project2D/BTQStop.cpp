#include "BTQStop.h"

BTQStop::BTQStop()
{
	m_bBehaviour = false;
}

BTQStop::~BTQStop()
{

}

EBehaviourResult BTQStop::Execute(Entity* pEntity, float deltaTime)
{
	if (Input::getInstance()->wasKeyPressed(INPUT_KEY_SPACE))
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