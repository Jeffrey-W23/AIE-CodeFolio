#include "FollowState.h"
#include "Vector2.h"
#include "Entity.h"

class Entity;

FollowState::FollowState()
{
	m_behaviours.PushBack(new Follow(1.0f));
	// add another behaviour
}

FollowState::~FollowState()
{
	for (unsigned i = 0; i < m_behaviours.Size(); ++i)
	{
		delete m_behaviours[i];
	}
}

void FollowState::onEnter(AIStateMachine* pMachine)
{
}

void FollowState::onExit(AIStateMachine* pMachine)
{
}

void FollowState::onUpdate(float deltaTime, Entity* pEntity, AIStateMachine* pMachine)
{
	Vector2 v2TotalForce; // Ask about this

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

void FollowState::onDraw(Renderer2D* m_2dRenderer)
{
}
