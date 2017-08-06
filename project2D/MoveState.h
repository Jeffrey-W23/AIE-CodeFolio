// #include, using, etc
#pragma once
#include "AIState.h"
#include "Renderer2D.h"
#include "Follow.h"
using namespace aie;

//--------------------------------------------------------------------------------------
// MoveState object. Inheritance from AIState.
//--------------------------------------------------------------------------------------
class MoveState : public AIState
{
public:

	//--------------------------------------------------------------------------------------
	// Default Constructor.
	//--------------------------------------------------------------------------------------
	MoveState();

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	~MoveState();

	//--------------------------------------------------------------------------------------
	// onEnter: A virtual function from AIState that runs first when a state is loaded.
	//
	// Param:
	//		pMachine: a pointer to StateMachine.
	//--------------------------------------------------------------------------------------
	void onEnter(AIStateMachine* pMachine);

	//--------------------------------------------------------------------------------------
	// onExit: A virtual function from AIState that runs on state exit.
	//
	// Param:
	//		pMachine: a pointer to StateMachine.
	//--------------------------------------------------------------------------------------
	void onExit(AIStateMachine* pMachine);

	//--------------------------------------------------------------------------------------
	// onUpdate: A virtual function from AIState to update objects.
	//
	// Param:
	//		deltaTime: Pass in deltaTime. A number that updates per second.
	//		pMachine: a pointer to StateMachine.
	//--------------------------------------------------------------------------------------
	void onUpdate(float deltaTime, Entity* pEntity, AIStateMachine* pMachine);

	//--------------------------------------------------------------------------------------
	// onDraw: A virtual function from AIState to render (or "draw") objects to the screen.
	//
	// Param:
	//		renderer2D: a pointer to Renderer2D for rendering objects to screen.
	//--------------------------------------------------------------------------------------
	void onDraw(Renderer2D* m_2dRenderer);

private:

	//--------------------------------------------------------------------------------------
	// A bool for stoping the state update.
	//--------------------------------------------------------------------------------------
	bool m_bStop;
};