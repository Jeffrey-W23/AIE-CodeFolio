#pragma once
#include "DecisionQuestion.h"

class DecisionTree
{
public:
	DecisionTree();
	~DecisionTree();

	void Update(Entity* pEntity, float deltaTime);

private:
	DecisionQuestion* m_pRoot;
};

