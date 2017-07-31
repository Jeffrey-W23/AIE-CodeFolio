#pragma once
#include "BTBaseNode.h"
#include "Input.h"
#include <iostream>
using namespace std;
using namespace aie;

class BTQSeek : public BTBaseNode
{
public:
	BTQSeek();
	~BTQSeek();
	EBehaviourResult Execute(Entity* pEntity, float deltaTime);
};