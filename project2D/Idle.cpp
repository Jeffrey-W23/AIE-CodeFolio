#include "Idle.h"

Idle::Idle()
{
	m_timer = 0;
}

Idle::~Idle()
{
}

void Idle::onEnter(StateMachine* pMachine)
{
	m_timer = 0;
}

void Idle::onExit(StateMachine* pMachine)
{
	m_timer = 0;
}

void Idle::onUpdate(float deltaTime, StateMachine* pMachine)
{
	m_timer += deltaTime;

	if (m_timer > 3)
		pMachine->PushState(1);
}

void Idle::onDraw(Renderer2D* m_2dRenderer)
{

}