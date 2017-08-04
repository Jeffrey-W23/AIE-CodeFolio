#include "PlayerState.h"
#include "Input.h"
#include "Player.h"
#include "Grid.h"
#include "Font.h"

PlayerState::PlayerState()
{
	m_Player = new Player();
	m_Font = new Font("./font/consolas.ttf", 50);
	m_Font2 = new Font("./font/consolas.ttf", 25);
}

PlayerState::~PlayerState()
{
	delete m_Player;
}

void PlayerState::onEnter(StateMachine* pMachine)
{

}

void PlayerState::onExit(StateMachine* pMachine)
{
	//m_Player->SetPosition(Vector2(500, 360)); // Figure out to reset on start up of state

}

void PlayerState::onUpdate(float deltaTime, StateMachine* pMachine)
{
	m_Player->Update(deltaTime);
}

void PlayerState::onDraw(Renderer2D* m_2dRenderer)
{
	m_Player->Draw(m_2dRenderer);

	m_2dRenderer->setRenderColour(1, 0, 1, 1);
	m_2dRenderer->drawCircle(1140, 360, 30, 30);

	m_2dRenderer->setRenderColour(1, 1, 1, 1);
	m_2dRenderer->drawText(m_Font, "2. PLAYER", 40, 45);
	m_2dRenderer->drawText(m_Font2, " - PRESS SPACE BAR TO STOP AND START THE AI EXAMPLE.", 285, 55);
}