#pragma once
#include "BTBaseNode.h"
#include "Input.h"
#include <iostream>
using namespace std;
using namespace aie;

class BTQFlee : public BTBaseNode
{
public:
	BTQFlee();
	~BTQFlee();
	EBehaviourResult Execute(Entity* pEntity, float deltaTime);

private:
	bool m_bBehaviour;
};