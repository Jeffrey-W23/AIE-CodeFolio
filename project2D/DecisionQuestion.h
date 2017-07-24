#pragma once
#include "BaseDecision.h"

class DecisionQuestion : public BaseDecision
{
public:
	virtual void MakeDecision(BaseAgent* pAgent, float deltaTime) = 0;

	BaseDecision* m_pTrueDecision;
	BaseDecision* m_pFalseDecision;
};