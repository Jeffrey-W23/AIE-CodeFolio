#include "Idle.h"

Idle::Idle()
{
	m_timer = 0;
}

Idle::~Idle()
{
}

void Idle::onEnter(AIStateMachine* pMachine)
{
	m_timer = 0;
}

void Idle::onExit(AIStateMachine* pMachine)
{
	m_timer = 0;
}

void Idle::onUpdate(float deltaTime, BaseAgent* agent, AIStateMachine* pMachine)
{
	for (int i = 0; i < m_behaviours.Size(); ++i)
		m_behaviours[i]->Update(agent, deltaTime);

	m_timer += deltaTime;

	if (m_timer > 3) // What happens if 1 isnt Patrol? What happens if I want to just always be idle.
	{
		/*if ()*/
			pMachine->PushState(1);
	}
}

void Idle::onDraw(Renderer2D* m_2dRenderer)
{

}