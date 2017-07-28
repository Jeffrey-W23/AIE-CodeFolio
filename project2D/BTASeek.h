#pragma once
#include "BTBaseNode.h"
#include <iostream>
#include "DynamicArray.h"
using namespace std;

class IBehaviour;

class BTASeek : public BTBaseNode
{
public:
	BTASeek();
	~BTASeek();
	EBehaviourResult Execute(Entity* pEntity, float deltaTime);

private:
	DynamicArray<IBehaviour*> m_behaviours;
};