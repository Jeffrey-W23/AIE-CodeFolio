// #include, using, etc
#include "BehaviourState.h"
#include "Input.h"
#include "BehaviourEntity.h"
#include "Grid.h"
#include "OAMap.h"
#include "Font.h"

//--------------------------------------------------------------------------------------
// Default Constructor.
//--------------------------------------------------------------------------------------
BehaviourState::BehaviourState()
{
	// Create new instance of the Behavior Entity.
	m_Enemy = new BehaviourEntity();

	// Create a new instances of the font.
	m_Font = new Font("./font/consolas.ttf", 50);
	m_Font2 = new Font("./font/consolas.ttf", 25);
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
BehaviourState::~BehaviourState()
{
	delete m_Enemy;
	delete m_Font;
	delete m_Font2;
}

//--------------------------------------------------------------------------------------
// onEnter: A virtual function from state that runs first when a state is loaded.
//
// Param:
//		pMachine: a pointer to StateMachine.
//--------------------------------------------------------------------------------------
void BehaviourState::onEnter(StateMachine* pMachine)
{
}

//--------------------------------------------------------------------------------------
// onExit: A virtual function from state that runs on state exit.
//
// Param:
//		pMachine: a pointer to StateMachine.
//--------------------------------------------------------------------------------------
void BehaviourState::onExit(StateMachine* pMachine)
{
}

//--------------------------------------------------------------------------------------
// onUpdate: A virtual function from state to update objects.
//
// Param:
//		deltaTime: Pass in deltaTime. A number that updates per second.
//		pMachine: a pointer to StateMachine.
//--------------------------------------------------------------------------------------
void BehaviourState::onUpdate(float deltaTime, StateMachine* pMachine)
{
	m_Enemy->Update(deltaTime);
}

//--------------------------------------------------------------------------------------
// onDraw: A virtual function from state to render (or "draw") objects to the screen.
//
// Param:
//		renderer2D: a pointer to Renderer2D for rendering objects to screen.
//--------------------------------------------------------------------------------------
void BehaviourState::onDraw(Renderer2D* m_2dRenderer)
{
	// Draw the OAMap. A Map of Objects that can be collided with.
	OAMap::Instance()->Draw(m_2dRenderer);
	
	// Draw the entity.
	m_Enemy->Draw(m_2dRenderer);

	// Draw the instruction text.
	m_2dRenderer->setRenderColour(1, 1, 1, 1);
	m_2dRenderer->drawText(m_Font, "5. BEHAVIORTREE -", 40, 45);
	m_2dRenderer->drawText(m_Font2, "      BEHAVIOURTREE EXAMPLE, ARRIVE WEIGHTED AGAINST", 450, 70);
	m_2dRenderer->drawText(m_Font2, "      COLLISIONAVOIDANCE. FOLLOWS MOUSE, SPACE START/STOP.", 450, 35);
}