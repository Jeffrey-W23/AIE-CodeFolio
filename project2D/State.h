#pragma once

class StateMachine;

//--------------------------------------------------------------------------------------
// State object. Inheritance from State.
//--------------------------------------------------------------------------------------
class State
{
public:

	//--------------------------------------------------------------------------------------
	// Default Constructor.
	//--------------------------------------------------------------------------------------
	State();

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	virtual ~State();

	//--------------------------------------------------------------------------------------
	// onEnter: A virtual function that runs first when a state is loaded.
	//
	// Param:
	//		pMachine: a pointer to StateMachine.
	//--------------------------------------------------------------------------------------
	virtual void onEnter() = 0;

	//--------------------------------------------------------------------------------------
	// onUpdate: A virtual function to update objects.
	//
	// Param:
	//		deltaTime: Pass in deltaTime. A number that updates per second.
	//		pMachine: a pointer to StateMachine.
	//--------------------------------------------------------------------------------------
	virtual void onUpdate() = 0;

	//--------------------------------------------------------------------------------------
	// onDraw: A virtual function to render (or "draw") objects to the screen.
	//
	// Param:
	//		renderer2D: a pointer to Renderer2D for rendering objects to screen.
	//--------------------------------------------------------------------------------------
	virtual void onDraw() = 0;
	
	//--------------------------------------------------------------------------------------
	// onExit: A virtual function that runs on state exit.
	//
	// Param:
	//		pMachine: a pointer to StateMachine.
	//--------------------------------------------------------------------------------------
	virtual void onExit() = 0;
};