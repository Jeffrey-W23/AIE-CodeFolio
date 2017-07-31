#pragma once
#include "BTBaseNode.h"
#include "Input.h"
#include <iostream>
using namespace std;
using namespace aie;

class BTQStop : public BTBaseNode
{
public:
	BTQStop();
	~BTQStop();
	EBehaviourResult Execute(Entity* pEntity, float deltaTime);
};