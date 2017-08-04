#include "SeekFleeState.h"
#include "Input.h"
#include "Enemy1.h"
#include "Grid.h"
#include "Font.h"

SeekFleeState::SeekFleeState()
{
	m_Enemy1 = new Enemy1();
	m_Font = new Font("./font/consolas.ttf", 50);
	m_Font2 = new Font("./font/consolas.ttf", 25);
}

SeekFleeState::~SeekFleeState()
{
	delete m_Enemy1;
}

void SeekFleeState::onEnter(StateMachine* pMachine)
{
}

void SeekFleeState::onExit(StateMachine* pMachine)
{
	// m_Enemy1->SetPosition(Vector2(500, 360)); // Figure out to reset on start up of state
}

void SeekFleeState::onUpdate(float deltaTime, StateMachine* pMachine)
{
	m_Enemy1->Update(deltaTime);
}

void SeekFleeState::onDraw(Renderer2D* m_2dRenderer)
{
	m_Enemy1->Draw(m_2dRenderer);

	m_2dRenderer->setRenderColour(1, 0, 1, 1);
	m_2dRenderer->drawCircle(1140, 360, 30, 30);

	m_2dRenderer->setRenderColour(1, 1, 1, 1);
	m_2dRenderer->drawText(m_Font, "3. SEEKFLEE", 40, 45);
	m_2dRenderer->drawText(m_Font2, " - PRESS SPACE BAR TO STOP AND START THE AI EXAMPLE.", 340, 55);
}