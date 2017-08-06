// #include, using, etc
#include "FlockState.h"
#include "Vector2.h"
#include "Entity.h"
#include "Flocking.h"
#include "Seek.h"
#include "Input.h"

//--------------------------------------------------------------------------------------
// Default Constructor.
//--------------------------------------------------------------------------------------
FlockState::FlockState(DynamicArray<Boid*>* aEntityList)
{
	// Push Flocking behaviour to behaviours array.
	m_behaviours.PushBack(new Flocking(1.0f, aEntityList));

	// Start the state as pause.
	m_bStop = true;
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
FlockState::~FlockState()
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
void FlockState::onEnter(AIStateMachine* pMachine)
{
}

//--------------------------------------------------------------------------------------
// onExit: A virtual function from AIState that runs on state exit.
//
// Param:
//		pMachine: a pointer to StateMachine.
//--------------------------------------------------------------------------------------
void FlockState::onExit(AIStateMachine* pMachine)
{
}

//--------------------------------------------------------------------------------------
// onUpdate: A virtual function from AIState to update objects.
//
// Param:
//		deltaTime: Pass in deltaTime. A number that updates per second.
//		pMachine: a pointer to StateMachine.
//--------------------------------------------------------------------------------------
void FlockState::onUpdate(float deltaTime, Entity* pEntity, AIStateMachine* pMachine)
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

		Vector2 vel = pEntity->GetVelocity();
		vel += v2TotalForce;

		if (vel.magnitude() > 80)
		{
			vel.normalise();
			vel = vel * 80.0f;
		}

		// Set the position and velocity to the entity.
		pEntity->SetVelocity(vel);
		pEntity->SetPosition(pEntity->GetPosition() + vel * deltaTime);
	}
}

//--------------------------------------------------------------------------------------
// onDraw: A virtual function from AIState to render (or "draw") objects to the screen.
//
// Param:
//		renderer2D: a pointer to Renderer2D for rendering objects to screen.
//--------------------------------------------------------------------------------------
void FlockState::onDraw(Renderer2D* m_2dRenderer)
{
}
