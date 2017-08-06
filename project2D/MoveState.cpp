// #include, using, etc
#include "MoveState.h"
#include "Vector2.h"
#include "Entity.h"
#include "Flee.h"
#include "Seek.h"
#include "Input.h"

//--------------------------------------------------------------------------------------
// Default Constructor.
//--------------------------------------------------------------------------------------
MoveState::MoveState()
{
	// Push Seek Behaviour and Flee to behaviours array.
	m_behaviours.PushBack(new Flee(0.6f, false));
	m_behaviours.PushBack(new Seek(1.0f));

	// Start the state as pause.
	m_bStop = true;
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
MoveState::~MoveState()
{
	for (unsigned i = 0; i < m_behaviours.Size(); ++i)
	{
		delete m_behaviours[i];
	}
}

//--------------------------------------------------------------------------------------
// onEnter: A virtual function from AIState that runs first when a state is loaded.
//
// Param:
//		pMachine: a pointer to StateMachine.
//--------------------------------------------------------------------------------------
void MoveState::onEnter(AIStateMachine* pMachine)
{
}

//--------------------------------------------------------------------------------------
// onExit: A virtual function from AIState that runs on state exit.
//
// Param:
//		pMachine: a pointer to StateMachine.
//--------------------------------------------------------------------------------------
void MoveState::onExit(AIStateMachine* pMachine)
{
}

//--------------------------------------------------------------------------------------
// onUpdate: A virtual function from AIState to update objects.
//
// Param:
//		deltaTime: Pass in deltaTime. A number that updates per second.
//		pMachine: a pointer to StateMachine.
//--------------------------------------------------------------------------------------
void MoveState::onUpdate(float deltaTime, Entity* pEntity, AIStateMachine* pMachine)
{
	// Input instance.
	aie::Input* input = aie::Input::getInstance();

	// Press space to toggle start and stop the state.
	if (input->wasKeyPressed(aie::INPUT_KEY_SPACE))
	{
		m_bStop = !m_bStop;
	}

	if (m_bStop == false)
	{
		Vector2 v2TotalForce;

		// Update each of the behaviours and apply the weight of other behaviours.
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

		// Set the position and velocity to the entity.
		pEntity->SetVelocity(v2TotalForce);
		pEntity->SetPosition(pEntity->GetPosition() + v2TotalForce);
	}
}

//--------------------------------------------------------------------------------------
// onDraw: A virtual function from AIState to render (or "draw") objects to the screen.
//
// Param:
//		renderer2D: a pointer to Renderer2D for rendering objects to screen.
//--------------------------------------------------------------------------------------
void MoveState::onDraw(Renderer2D* m_2dRenderer)
{
}
