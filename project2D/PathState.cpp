// #include, using, etc
#include "PathState.h"
#include "Input.h"
#include "PathFindEntity1.h"
#include "PathFindEntity2.h"
#include "Grid.h"
#include "Font.h"

//--------------------------------------------------------------------------------------
// Default Constructor.
//--------------------------------------------------------------------------------------
PathState::PathState()
{
	// Create new instance of the Behavior Entity.
	m_Enemy = new PathFindEntity1();
	m_Enemy2 = new PathFindEntity2();

	// Create a new instances of the font.
	m_Font = new Font("./font/consolas.ttf", 50);
	m_Font2 = new Font("./font/consolas.ttf", 25);
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
PathState::~PathState()
{
	delete m_Enemy;
	delete m_Enemy2;
	delete m_Font;
	delete m_Font2;
}

//--------------------------------------------------------------------------------------
// onEnter: A virtual function from state that runs first when a state is loaded.
//
// Param:
//		pMachine: a pointer to StateMachine.
//--------------------------------------------------------------------------------------
void PathState::onEnter(StateMachine* pMachine)
{
}

//--------------------------------------------------------------------------------------
// onExit: A virtual function from state that runs on state exit.
//
// Param:
//		pMachine: a pointer to StateMachine.
//--------------------------------------------------------------------------------------
void PathState::onExit(StateMachine* pMachine)
{
}

//--------------------------------------------------------------------------------------
// onUpdate: A virtual function from state to update objects.
//
// Param:
//		deltaTime: Pass in deltaTime. A number that updates per second.
//		pMachine: a pointer to StateMachine.
//--------------------------------------------------------------------------------------
void PathState::onUpdate(float deltaTime, StateMachine* pMachine)
{
	m_Enemy->Update(deltaTime);
	m_Enemy2->Update(deltaTime);
}

//--------------------------------------------------------------------------------------
// onDraw: A virtual function from state to render (or "draw") objects to the screen.
//
// Param:
//		renderer2D: a pointer to Renderer2D for rendering objects to screen.
//--------------------------------------------------------------------------------------
void PathState::onDraw(Renderer2D* m_2dRenderer)
{
	// Draw the astar grid.
	Grid::Instance()->DrawGrid(m_2dRenderer);

	// Draw the entities.
	m_Enemy->Draw(m_2dRenderer);
	m_Enemy2->Draw(m_2dRenderer);

	// Draw the instruction text.
	m_2dRenderer->setRenderColour(0.150, 0.150, 0.150, 1);
	m_2dRenderer->drawBox(127, 720, 200, 80);
	m_2dRenderer->setRenderColour(1, 1, 1, 1);
	m_2dRenderer->drawText(m_Font, "1. PATHFINDING -", 40, 45);
	m_2dRenderer->drawText(m_Font2, "      2 ENTITIES, ASTAR PATH FINDING ON A 10x10 GRID.", 425, 70);
	m_2dRenderer->drawText(m_Font2, "      PRESS NUMBER KEYS TO SEE OTHER AI EXAMPLES.", 425, 35);
}