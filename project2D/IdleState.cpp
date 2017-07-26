#include "IdleState.h"
#include "AIStateMachine.h"

IdleState::IdleState()
{
	m_timer = 0;
}

IdleState::~IdleState()
{
}

void IdleState::onEnter(AIStateMachine* pMachine)
{
	m_timer = 0;
}

void IdleState::onExit(AIStateMachine* pMachine)
{
	m_timer = 0;
}

void IdleState::onUpdate(float deltaTime, Entity* pEntity, AIStateMachine* pMachine)
{
	for (int i = 0; i < m_behaviours.Size(); ++i)
		m_behaviours[i]->Update(pEntity, deltaTime);

	m_timer += deltaTime;

	if (m_timer > 3)
	{
			pMachine->PushState(1);
	}
}

void IdleState::onDraw(Renderer2D* m_2dRenderer)
{

}