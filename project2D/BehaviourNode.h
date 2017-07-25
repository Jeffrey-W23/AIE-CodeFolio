#pragma once

enum EBehaviourResult
{
	EBHAVIOUR_FAILURE,
	EBHAVIOUR_SUCCESS,
	EBHAVIOUR_PENDING
};

class BehaviourNode
{
public:
	virtual ~BehaviourNode() {};
	virtual EBehaviourResult Execute() = 0; //BaseAgent* pAgent
};