#include "ControllerState.h"
#include "Input.h"
#include "Vector2.h"
#include "Flee.h"
#include "KeyboardController.h"
#include "Entity.h"

ControllerState::ControllerState()
{
	m_behaviours.PushBack(new KeyboardController(1.0f));
	m_behaviours.PushBack(new Flee(0.6f, false));

	m_bStop = true;
}

ControllerState::~ControllerState()
{
	for (unsigned i = 0; i < m_behaviours.Size(); ++i)
	{
		delete m_behaviours[i];
	}
}

void ControllerState::onEnter(AIStateMachine* pMachine)
{
}

void ControllerState::onExit(AIStateMachine* pMachine)
{
}

void ControllerState::onUpdate(float deltaTime, Entity* pEntity, AIStateMachine* pMachine)
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

		pEntity->SetPosition(pEntity->GetPosition() + v2TotalForce);
	}
}

void ControllerState::onDraw(Renderer2D* m_2dRenderer)
{
}