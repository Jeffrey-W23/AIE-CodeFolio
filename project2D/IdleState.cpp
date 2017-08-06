// #include, using, etc
#include "IdleState.h"
#include "AIStateMachine.h"

//--------------------------------------------------------------------------------------
// Default Constructor.
//--------------------------------------------------------------------------------------
IdleState::IdleState()
{
	m_timer = 0;
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
IdleState::~IdleState()
{
}

//--------------------------------------------------------------------------------------
// onEnter: A virtual function from AIState that runs first when a state is loaded.
//
// Param:
//		pMachine: a pointer to StateMachine.
//--------------------------------------------------------------------------------------
void IdleState::onEnter(AIStateMachine* pMachine)
{
	m_timer = 0;
}

//--------------------------------------------------------------------------------------
// onExit: A virtual function from AIState that runs on state exit.
//
// Param:
//		pMachine: a pointer to StateMachine.
//--------------------------------------------------------------------------------------
void IdleState::onExit(AIStateMachine* pMachine)
{
	m_timer = 0;
}

//--------------------------------------------------------------------------------------
// onUpdate: A virtual function from AIState to update objects.
//
// Param:
//		deltaTime: Pass in deltaTime. A number that updates per second.
//		pMachine: a pointer to StateMachine.
//--------------------------------------------------------------------------------------
void IdleState::onUpdate(float deltaTime, Entity* pEntity, AIStateMachine* pMachine)
{
	// Update each of the Behaviours in the Behaviours array.
	for (int i = 0; i < m_behaviours.Size(); ++i)
		m_behaviours[i]->Update(pEntity, deltaTime);

	// Update timer by deltaTime
	m_timer += deltaTime;

	// After timer passes 3 push follow state.
	if (m_timer > 3)
	{
			pMachine->PushState(1);
	}
}

//--------------------------------------------------------------------------------------
// onDraw: A virtual function from AIState to render (or "draw") objects to the screen.
//
// Param:
//		renderer2D: a pointer to Renderer2D for rendering objects to screen.
//--------------------------------------------------------------------------------------
void IdleState::onDraw(Renderer2D* m_2dRenderer)
{

}