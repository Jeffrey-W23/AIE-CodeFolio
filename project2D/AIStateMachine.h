//#include, using etc
#pragma once
#include "DynamicArray.h" 
#include "AIState.h"
#include "Stack.h"
#include "Renderer2D.h"
using namespace aie;

//--------------------------------------------------------------------------------------
// ShareManager object.
//--------------------------------------------------------------------------------------
class AIStateMachine
{
public:

	//--------------------------------------------------------------------------------------
	// Default Constructor.
	//--------------------------------------------------------------------------------------
	AIStateMachine();

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	~AIStateMachine();

	//--------------------------------------------------------------------------------------
	// Update: A function to update states over time.
	//
	// Param:
	//		deltaTime: Pass in deltaTime. A number that updates per second.
	//--------------------------------------------------------------------------------------
	void Update(float deltaTime, Entity* pEntity);

	//--------------------------------------------------------------------------------------
	// Draw: A function to render (or "draw") states to the screen.
	//
	// Param:
	//		renderer2D: a pointer to Renderer2D for rendering objects to screen.
	//--------------------------------------------------------------------------------------
	void Draw(Renderer2D* m_2dRenderer);

	//--------------------------------------------------------------------------------------
	// PushState: A function to push a state onto the statemachine stack.
	//
	// Param:
	//		nStateIndex: An int index for the state you want to push
	//--------------------------------------------------------------------------------------
	void PushState(int nStateIndex);

	//--------------------------------------------------------------------------------------
	// AddState: A function to render (or "draw") states to the screen.
	//
	// Param:
	//		nStateIndex: An int index for the state.
	//		pState: A pointer to a state.
	//--------------------------------------------------------------------------------------
	void AddState(int nStateIndex, AIState* pState);

	//--------------------------------------------------------------------------------------
	// PopState: Take the current state off the stack.
	//--------------------------------------------------------------------------------------
	void PopState();

	//--------------------------------------------------------------------------------------
	// PopAll: Take all states off the stack.
	//--------------------------------------------------------------------------------------
	void PopAll();

	//--------------------------------------------------------------------------------------
	// SetBackgroundUpdate: A function to turn background updating on or off.
	//
	// Param:
	//		onoff: a bool for turning off and on.
	//--------------------------------------------------------------------------------------
	void SetBackgroundUpdate(bool onoff);

private:

	//--------------------------------------------------------------------------------------
	// A DynamicArray of State pointers m_StateList
	//--------------------------------------------------------------------------------------
	DynamicArray<AIState*> m_StateList;

	//--------------------------------------------------------------------------------------
	// A Stack of State pointers m_CurrentStack
	//--------------------------------------------------------------------------------------
	Stack<AIState*> m_CurrentStack;

	//--------------------------------------------------------------------------------------
	// A bool backUpdate for if the background state should be updated or not
	//--------------------------------------------------------------------------------------
	bool backUpdate;
};