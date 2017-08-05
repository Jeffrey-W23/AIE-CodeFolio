#pragma once
#include "BTBaseNode.h"
#include "Input.h"
#include <iostream>
using namespace std;
using namespace aie;

class BTQObAv : public BTBaseNode
{
public:
	BTQObAv();
	~BTQObAv();
	EBehaviourResult Execute(Entity* pEntity, float deltaTime);
};