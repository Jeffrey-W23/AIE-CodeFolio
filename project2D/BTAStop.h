#pragma once
#include "BTBaseNode.h"
#include <iostream>
using namespace std;

class BTAStop : public BTBaseNode
{
public:
	BTAStop();
	~BTAStop();
	EBehaviourResult Execute(Entity* pEntity, float deltaTime);
};