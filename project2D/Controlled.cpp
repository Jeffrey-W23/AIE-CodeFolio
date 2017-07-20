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
}

void Controlled::onEnter(StateMachine* pMachine)
{
}

void Controlled::onExit(StateMachine* pMachine)
{
}

void Controlled::onUpdate(float deltaTime, StateMachine* pMachine)
{
	for (int i = 0; i < m_behaviours.Size(); ++i)
		m_behaviours[i]->Update(this, deltaTime);
}

void Controlled::onDraw(Renderer2D* m_2dRenderer)
{

}