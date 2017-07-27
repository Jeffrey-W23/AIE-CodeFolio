#pragma once
#include "BaseDecision.h"

class BaseAnwser : public BaseDecision
{
public:
	BaseAnwser() {};
	virtual ~BaseAnwser() {};
	virtual void MakeDecision(Entity* pEntity, float deltaTime) = 0;
};