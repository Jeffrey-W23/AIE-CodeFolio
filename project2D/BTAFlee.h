#pragma once
#include "BTBaseNode.h"
#include <iostream>
#include "DynamicArray.h"
using namespace std;

class IBehaviour;

class BTAFlee : public BTBaseNode
{
public:
	BTAFlee();
	~BTAFlee();
	EBehaviourResult Execute(Entity* pEntity, float deltaTime);

private:
	DynamicArray<IBehaviour*> m_behaviours;
};