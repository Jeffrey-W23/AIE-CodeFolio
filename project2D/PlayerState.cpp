// #include, using, etc
#include "PlayerState.h"
#include "Input.h"
#include "Player.h"
#include "Grid.h"
#include "Font.h"

//--------------------------------------------------------------------------------------
// Default Constructor.
//--------------------------------------------------------------------------------------
PlayerState::PlayerState()
{
	// Create new instance of the Behavior Entity.
	m_Player = new Player();

	// Create a new instances of the font.
	m_Font = new Font("./font/consolas.ttf", 50);
	m_Font2 = new Font("./font/consolas.ttf", 25);
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
PlayerState::~PlayerState()
{
	delete m_Player;
	delete m_Font;
	delete m_Font2;
}

//--------------------------------------------------------------------------------------
// onEnter: A virtual function from state that runs first when a state is loaded.
//
// Param:
//		pMachine: a pointer to StateMachine.
//--------------------------------------------------------------------------------------
void PlayerState::onEnter(StateMachine* pMachine)
{

}

//--------------------------------------------------------------------------------------
// onExit: A virtual function from state that runs on state exit.
//
// Param:
//		pMachine: a pointer to StateMachine.
//--------------------------------------------------------------------------------------
void PlayerState::onExit(StateMachine* pMachine)
{
}

//--------------------------------------------------------------------------------------
// onUpdate: A virtual function from state to update objects.
//
// Param:
//		deltaTime: Pass in deltaTime. A number that updates per second.
//		pMachine: a pointer to StateMachine.
//--------------------------------------------------------------------------------------
void PlayerState::onUpdate(float deltaTime, StateMachine* pMachine)
{
	m_Player->Update(deltaTime);
}

//--------------------------------------------------------------------------------------
// onDraw: A virtual function from state to render (or "draw") objects to the screen.
//
// Param:
//		renderer2D: a pointer to Renderer2D for rendering objects to screen.
//--------------------------------------------------------------------------------------
void PlayerState::onDraw(Renderer2D* m_2dRenderer)
{
	// Draw the Player entity.
	m_Player->Draw(m_2dRenderer);

	// Draw the flee point.
	m_2dRenderer->setRenderColour(1, 0, 1, 1);
	m_2dRenderer->drawCircle(1140, 360, 30, 30);
	m_2dRenderer->drawText(m_Font2, "^ FLEE", 1130, 300);
	m_2dRenderer->drawText(m_Font2, "  POINT", 1130, 275);

	// Draw the instruction text.
	m_2dRenderer->setRenderColour(1, 1, 1, 1);
	m_2dRenderer->drawText(m_Font, "2. PLAYER -", 40, 45);
	m_2dRenderer->drawText(m_Font2, "      CONTROLLER BEHAVIOUR WEIGHTED AGAINST FLEE BEHAVIOUR.", 285, 70);
	m_2dRenderer->drawText(m_Font2, "      PRESS SPACE BAR TO STOP AND START THE AI EXAMPLE.", 285, 35);
}