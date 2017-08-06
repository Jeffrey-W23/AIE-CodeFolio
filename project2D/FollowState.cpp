// #include, using, etc
#include "FollowState.h"
#include "Vector2.h"
#include "Entity.h"

//--------------------------------------------------------------------------------------
// Default Constructor.
//--------------------------------------------------------------------------------------
FollowState::FollowState(int nStart, int nEnd)
{
	// Push Follow behaviour to behaviours array.
	m_behaviours.PushBack(new Follow(1.0f, nStart, nEnd));
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
FollowState::~FollowState()
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
void FollowState::onEnter(AIStateMachine* pMachine)
{
}

//--------------------------------------------------------------------------------------
// onExit: A virtual function from AIState that runs on state exit.
//
// Param:
//		pMachine: a pointer to StateMachine.
//--------------------------------------------------------------------------------------
void FollowState::onExit(AIStateMachine* pMachine)
{
}

//--------------------------------------------------------------------------------------
// onUpdate: A virtual function from AIState to update objects.
//
// Param:
//		deltaTime: Pass in deltaTime. A number that updates per second.
//		pMachine: a pointer to StateMachine.
//--------------------------------------------------------------------------------------
void FollowState::onUpdate(float deltaTime, Entity* pEntity, AIStateMachine* pMachine)
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

//--------------------------------------------------------------------------------------
// onDraw: A virtual function from AIState to render (or "draw") objects to the screen.
//
// Param:
//		renderer2D: a pointer to Renderer2D for rendering objects to screen.
//--------------------------------------------------------------------------------------
void FollowState::onDraw(Renderer2D* m_2dRenderer)
{
}
