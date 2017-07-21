#include "Patrol.h"

Patrol::Patrol()
{
}

Patrol::~Patrol()
{
}

void Patrol::onEnter(AIStateMachine* pMachine)
{

}

void Patrol::onExit(AIStateMachine* pMachine)
{

}

void Patrol::onUpdate(float deltaTime, BaseAgent* agent, AIStateMachine* pMachine)
{
	for (int i = 0; i < m_behaviours.Size(); ++i)
		m_behaviours[i]->Update(agent, deltaTime);
}

void Patrol::onDraw(Renderer2D* m_2dRenderer)
{

}
