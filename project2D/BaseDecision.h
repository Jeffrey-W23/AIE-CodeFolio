#pragma once

class BaseAgent;

class BaseDecision 
{
public:
	virtual void MakeDecision(BaseAgent* pAgent, float deltaTime) = 0;
};