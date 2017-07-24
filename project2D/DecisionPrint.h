#pragma once
#include "BaseDecision.h"

class DecisionPrint : public BaseDecision
{
public:
	DecisionPrint();
	~DecisionPrint();

	void MakeDecision(BaseAgent* pAgent, float deltaTime);

private:
	float m_timer;
};

