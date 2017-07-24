#pragma once
#include "DecisionQuestion.h"

class DecisionTree
{
public:
	DecisionTree();
	~DecisionTree();

	void Update(BaseAgent* pAgent, float deltaTime);

private:
	DecisionQuestion* m_pRoot;
};

