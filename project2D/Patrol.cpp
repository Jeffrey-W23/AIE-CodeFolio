#include "Patrol.h"
#include "Vector2.h"
#include "BaseAgent.h"

class BaseAgent;

Patrol::Patrol()
{
	m_follow = new Follow();
	m_behaviours.PushBack(m_follow);
}

Patrol::~Patrol()
{
	delete m_follow;
}

void Patrol::onEnter(AIStateMachine* pMachine)
{
}

void Patrol::onExit(AIStateMachine* pMachine)
{
}

void Patrol::onUpdate(float deltaTime, Entity* pEntity, AIStateMachine* pMachine)
{
	for (int i = 0; i < m_behaviours.Size(); ++i)
		m_behaviours[i]->Update(pEntity, deltaTime);

	// an array of 4 end nodes

}

void Patrol::onDraw(Renderer2D* m_2dRenderer)
{
}
