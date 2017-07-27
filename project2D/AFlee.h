#pragma once
#include "BaseAnwser.h"
#include "DynamicArray.h"

class IBehaviour;

class AFlee : public BaseAnwser
{
public:
	AFlee();
	~AFlee();

	void MakeDecision(Entity* pEntity, float deltaTime);

private:
	DynamicArray<IBehaviour*> m_behaviours;
};

