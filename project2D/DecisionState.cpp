// #include, using, etc
#include "DecisionState.h"
#include "Input.h"
#include "DecisionEntity.h"
#include "Grid.h"
#include "Font.h"

//--------------------------------------------------------------------------------------
// Default Constructor.
//--------------------------------------------------------------------------------------
DecisionState::DecisionState()
{
	// Create new instance of the Decision Entity.
	m_Enemy = new DecisionEntity();

	// Create a new instances of the font.
	m_Font = new Font("./font/consolas.ttf", 50);
	m_Font2 = new Font("./font/consolas.ttf", 25);
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
DecisionState::~DecisionState()
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
void DecisionState::onEnter(StateMachine* pMachine)
{
}

//--------------------------------------------------------------------------------------
// onExit: A virtual function from state that runs on state exit.
//
// Param:
//		pMachine: a pointer to StateMachine.
//--------------------------------------------------------------------------------------
void DecisionState::onExit(StateMachine* pMachine)
{
}

//--------------------------------------------------------------------------------------
// onUpdate: A virtual function from state to update objects.
//
// Param:
//		deltaTime: Pass in deltaTime. A number that updates per second.
//		pMachine: a pointer to StateMachine.
//--------------------------------------------------------------------------------------
void DecisionState::onUpdate(float deltaTime, StateMachine* pMachine)
{
	m_Enemy->Update(deltaTime);
}

//--------------------------------------------------------------------------------------
// onDraw: A virtual function from state to render (or "draw") objects to the screen.
//
// Param:
//		renderer2D: a pointer to Renderer2D for rendering objects to screen.
//--------------------------------------------------------------------------------------
void DecisionState::onDraw(Renderer2D* m_2dRenderer)
{
	// Draw the entity.
	m_Enemy->Draw(m_2dRenderer);

	// Draw the instruction text.
	m_2dRenderer->setRenderColour(1, 1, 1, 1);
	m_2dRenderer->drawText(m_Font, "4. DECISIONTREE -", 40, 45);
	m_2dRenderer->drawText(m_Font2, "      DECISIONTREE EXAMPLE, SEEK AND FLEE FROM THE MOUSE.", 450, 70);
	m_2dRenderer->drawText(m_Font2, "      S TO SEEK, F TO FLEE. SPACE TO START/STOP EXAMPLE.", 450, 35);
}