#include "BTQSeek.h"

BTQSeek::BTQSeek()
{
	m_bBehaviour = false;
}

BTQSeek::~BTQSeek()
{

}

EBehaviourResult BTQSeek::Execute(Entity* pEntity, float deltaTime)
{
	if (Input::getInstance()->wasKeyPressed(INPUT_KEY_S))
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