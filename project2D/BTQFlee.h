#pragma once
#include "BTBaseNode.h"
#include "Input.h"
#include <iostream>
using namespace std;
using namespace aie;

class BTQFlee : public BTBaseNode
{
	bool m_bBehaviour;

	EBehaviourResult Execute(Entity* pEntity, float deltaTime)
	{
		if (Input::getInstance()->wasKeyPressed(INPUT_KEY_2))
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