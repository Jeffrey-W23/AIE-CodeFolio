#include "MoveState.h"
#include "Vector2.h"
#include "Entity.h"
#include "Flee.h"
#include "Seek.h"

class Entity;

MoveState::MoveState()
{
	//m_behaviours.PushBack(new Flee(0.5f)); // Memory leak?
	//m_behaviours.PushBack(new Seek(1.0f)); // Memory leak?
}

MoveState::~MoveState()
{
	for (unsigned i = 0; i < m_behaviours.Size(); ++i)
	{
		delete m_behaviours[i];
	}
}

void MoveState::onEnter(AIStateMachine* pMachine)
{
}

void MoveState::onExit(AIStateMachine* pMachine)
{
}

void MoveState::onUpdate(float deltaTime, Entity* pEntity, AIStateMachine* pMachine)
{
	Vector2 v2TotalForce;

	for (unsigned int i = 0; i < m_behaviours.Size(); ++i)
	{
		Vector2 currentForce = m_behaviours[i]->Update(pEntity, deltaTime);

		currentForce = currentForce * m_behaviours[i]->m_fWeighting;

		v2TotalForce = v2TotalForce + currentForce;

		float fMagnitude = v2TotalForce.magnitude();

		if (fMagnitude > 10.0f)
		{
			v2TotalForce.normalise();
			v2TotalForce = v2TotalForce * 10.0f;
			break;
		}
	}

	pEntity->SetPosition(pEntity->GetPosition() + v2TotalForce);
}

void MoveState::onDraw(Renderer2D* m_2dRenderer)
{
}
