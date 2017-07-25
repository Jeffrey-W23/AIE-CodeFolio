#pragma once
#include "BehaviourNode.h"
#include <iostream>
#include "Input.h"
using namespace aie;
using namespace std;

class ExampleQuestion : public BehaviourNode
{
public:
	EBehaviourResult Execute()
	{
		if (Input::getInstance()->isKeyDown(INPUT_KEY_SPACE))
		{
			return EBHAVIOUR_SUCCESS;
		}
		else
		{
			return EBHAVIOUR_FAILURE;
		}
	}
};