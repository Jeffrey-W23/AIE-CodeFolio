// #include, using, etc
#pragma once
#include "State.h"
#include "Renderer2D.h"
using namespace aie;

// forward declarations
class BehaviourEntity;

//--------------------------------------------------------------------------------------
// BehaviourState object. Inheritance from State.
//--------------------------------------------------------------------------------------
class BehaviourState : public State
{
public:
	
	//--------------------------------------------------------------------------------------
	// Default Constructor.
	//--------------------------------------------------------------------------------------
	BehaviourState();
	
	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	~BehaviourState();

	//--------------------------------------------------------------------------------------
	// onEnter: A virtual function from state that runs first when a state is loaded.
	//
	// Param:
	//		pMachine: a pointer to StateMachine.
	//--------------------------------------------------------------------------------------
	void onEnter(StateMachine* pMachine);
	
	//--------------------------------------------------------------------------------------
	// onExit: A virtual function from state that runs on state exit.
	//
	// Param:
	//		pMachine: a pointer to StateMachine.
	//--------------------------------------------------------------------------------------
	void onExit(StateMachine* pMachine);
	
	//--------------------------------------------------------------------------------------
	// onUpdate: A virtual function from state to update objects.
	//
	// Param:
	//		deltaTime: Pass in deltaTime. A number that updates per second.
	//		pMachine: a pointer to StateMachine.
	//--------------------------------------------------------------------------------------
	void onUpdate(float deltaTime, StateMachine* pMachine);
	
	//--------------------------------------------------------------------------------------
	// onDraw: A virtual function from state to render (or "draw") objects to the screen.
	//
	// Param:
	//		renderer2D: a pointer to Renderer2D for rendering objects to screen.
	//--------------------------------------------------------------------------------------
	void onDraw(Renderer2D* m_2dRenderer);

private:
	
	//--------------------------------------------------------------------------------------
	// A pointer to the behaviour entity.
	//--------------------------------------------------------------------------------------
	BehaviourEntity* m_Enemy;
	
	//--------------------------------------------------------------------------------------
	// A pointer to a Font m_font.
	//--------------------------------------------------------------------------------------
	Font* m_Font;
	
	//--------------------------------------------------------------------------------------
	// A pointer to a Font m_font2.
	//--------------------------------------------------------------------------------------
	Font* m_Font2;
};