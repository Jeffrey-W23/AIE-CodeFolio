#pragma once
#include "BaseDecision.h"

class BaseQuestion : public BaseDecision
{
public:
	BaseQuestion() {};
	virtual ~BaseQuestion() {};
	virtual void MakeDecision(Entity* pEntity, float deltaTime) = 0;

	BaseDecision* m_pTrueDecision;
	BaseDecision* m_pFalseDecision;
};