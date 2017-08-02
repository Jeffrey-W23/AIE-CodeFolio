#include "FlockState.h"
#include "Vector2.h"
#include "Entity.h"
#include "Flocking.h"
#include "Seek.h"
#include "Input.h"

FlockState::FlockState(DynamicArray<Boid*>* aEntityList)
{
	m_behaviours.PushBack(new Flocking(1.0f, aEntityList));
	//m_behaviours.PushBack(new Seek(0.6f));

	m_bStop = true;
}

FlockState::~FlockState()
{
	for (unsigned i = 0; i < m_behaviours.Size(); ++i)
	{
		delete m_behaviours[i];
	}
}

void FlockState::onEnter(AIStateMachine* pMachine)
{
}

void FlockState::onExit(AIStateMachine* pMachine)
{
}

void FlockState::onUpdate(float deltaTime, Entity* pEntity, AIStateMachine* pMachine)
{
	aie::Input* input = aie::Input::getInstance();

	if (input->wasKeyPressed(aie::INPUT_KEY_SPACE))
	{
		m_bStop = !m_bStop;
	}

	if (m_bStop == false)
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

		Vector2 vel = pEntity->GetVelocity();
		vel += v2TotalForce;

		if (vel.magnitude() > 80)
		{
			vel.normalise();
			vel = vel * 80.0f;
		}

		pEntity->SetVelocity(vel);
		pEntity->SetPosition(pEntity->GetPosition() + vel * deltaTime);
	}
}

void FlockState::onDraw(Renderer2D* m_2dRenderer)
{
}
