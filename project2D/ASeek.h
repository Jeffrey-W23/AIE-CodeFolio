#pragma once
#include "BaseAnwser.h"
#include "DynamicArray.h"

class IBehaviour;

class ASeek : public BaseAnwser
{
public:
	ASeek();
	~ASeek();

	void MakeDecision(Entity* pEntity, float deltaTime);

private:
	DynamicArray<IBehaviour*> m_behaviours;
};

