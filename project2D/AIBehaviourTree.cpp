#include "AIBehaviourTree.h"
#include "ExampleAction.h"
#include "ExampleQuestion.h"
#include "Selector.h"
#include "Sequence.h"
#include "BehaviourNode.h"

AIBehaviourTree::AIBehaviourTree()
{
	m_pRoot = new Selector();
	
	// LHS
	BehaviourNode* pFirst = new Sequence();
	BehaviourNode* pFirstFirst = new ExampleQuestion();
	BehaviourNode* pFirstSecond = new ExampleAction("ButtonPressed");
	((Composite*)pFirst)->children.PushBack(pFirstFirst);
	((Composite*)pFirst)->children.PushBack(pFirstSecond);

	// RHS
	BehaviourNode* pSecond = new ExampleAction("ButtonNotPressed");

	((Composite*)m_pRoot)->children.PushBack(pFirst);
	((Composite*)m_pRoot)->children.PushBack(pSecond);
}

AIBehaviourTree::~AIBehaviourTree()
{
	delete m_pRoot;
}

void AIBehaviourTree::Update(float deltaTime)
{
	m_pRoot->Execute();
}
