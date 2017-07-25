#include "Idle.h"
#include "AIStateMachine.h"

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

void Idle::onUpdate(float deltaTime, Entity* pEntity, AIStateMachine* pMachine)
{
	for (int i = 0; i < m_behaviours.Size(); ++i)
		m_behaviours[i]->Update(pEntity, deltaTime);

	m_timer += deltaTime;

	if (m_timer > 3)
	{
			pMachine->PushState(1);
	}
}

void Idle::onDraw(Renderer2D* m_2dRenderer)
{

}