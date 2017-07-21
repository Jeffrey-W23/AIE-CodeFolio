#include "Controlled.h"
#include "Input.h"
#include "Vector2.h"

class BaseAgent;

Controlled::Controlled()
{
	m_controller = new KeyboardController();
	m_behaviours.PushBack(m_controller);
}

Controlled::~Controlled()
{
	delete m_controller;
}

void Controlled::onEnter(AIStateMachine* pMachine)
{
}

void Controlled::onExit(AIStateMachine* pMachine)
{
}

void Controlled::onUpdate(float deltaTime, BaseAgent* agent, AIStateMachine* pMachine)
{
	for (int i = 0; i < m_behaviours.Size(); ++i)
		m_behaviours[i]->Update(agent, deltaTime);
}

void Controlled::onDraw(Renderer2D* m_2dRenderer)
{
}