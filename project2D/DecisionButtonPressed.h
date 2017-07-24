#pragma once
#include "DecisionQuestion.h"

class DecisionButtonPressed : public DecisionQuestion
{
public:
	DecisionButtonPressed();
	virtual ~DecisionButtonPressed();
	void MakeDecision(BaseAgent* pAgent, float deltaTime);

};