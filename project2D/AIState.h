#pragma once
#include "Renderer2D.h"
#include "DynamicArray.h"
#include "IBehaviour.h"
using namespace aie;

class AIStateMachine;
class Entity;

//--------------------------------------------------------------------------------------
// State object. Inheritance from State.
//--------------------------------------------------------------------------------------
class AIState
{
public:

	//--------------------------------------------------------------------------------------
	// Default Constructor.
	//--------------------------------------------------------------------------------------
	AIState();

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	virtual ~AIState();

	//--------------------------------------------------------------------------------------
	// onEnter: A virtual function that runs first when a state is loaded.
	//
	// Param:
	//		pMachine: a pointer to StateMachine.
	//--------------------------------------------------------------------------------------
	virtual void onEnter(AIStateMachine* pMachine) = 0;

	//--------------------------------------------------------------------------------------
	// onUpdate: A virtual function to update objects.
	//
	// Param:
	//		deltaTime: Pass in deltaTime. A number that updates per second.
	//		pMachine: a pointer to StateMachine.
	//--------------------------------------------------------------------------------------
	virtual void onUpdate(float deltaTime, Entity* pEntity, AIStateMachine* pMachine) = 0;

	//--------------------------------------------------------------------------------------
	// onDraw: A virtual function to render (or "draw") objects to the screen.
	//
	// Param:
	//		renderer2D: a pointer to Renderer2D for rendering objects to screen.
	//--------------------------------------------------------------------------------------
	virtual void onDraw(Renderer2D* m_2dRenderer) = 0;

	//--------------------------------------------------------------------------------------
	// onExit: A virtual function that runs on state exit.
	//
	// Param:
	//		pMachine: a pointer to StateMachine.
	//--------------------------------------------------------------------------------------
	virtual void onExit(AIStateMachine* pMachine) = 0;

protected:

	DynamicArray<IBehaviour*> m_behaviours;
};