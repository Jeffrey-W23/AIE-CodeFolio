#pragma once
#include "BTBaseNode.h"
#include "Input.h"
#include <iostream>
using namespace std;
using namespace aie;

class BTQSeek : public BTBaseNode
{
	bool m_bBehaviour;

	EBehaviourResult Execute(Entity* pEntity, float deltaTimes)
	{
		if (Input::getInstance()->wasKeyPressed(INPUT_KEY_1))
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
};