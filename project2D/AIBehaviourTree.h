#pragma once

class BehaviourNode;

class AIBehaviourTree
{
public:
	AIBehaviourTree();
	~AIBehaviourTree();

	void Update(float deltaTime);

	BehaviourNode* m_pRoot;
};

