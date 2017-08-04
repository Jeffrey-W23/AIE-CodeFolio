#include "PathState.h"
#include "Input.h"
#include "Enemy.h"
#include "Enemy4.h"
#include "Grid.h"
#include "Font.h"

PathState::PathState()
{
	m_Enemy = new Enemy();
	m_Enemy4 = new Enemy4();
	m_Font = new Font("./font/consolas.ttf", 50);
	m_Font2 = new Font("./font/consolas.ttf", 25);
}

PathState::~PathState()
{
	delete m_Enemy;
	delete m_Enemy4;
}

void PathState::onEnter(StateMachine* pMachine)
{
	//m_Enemy->SetPosition(Vector2(200, 150));
	//m_Enemy4->SetPosition(Vector2(200, 550)); // find a way of resetting it everytime I go back to this state
}

void PathState::onExit(StateMachine* pMachine)
{

}

void PathState::onUpdate(float deltaTime, StateMachine* pMachine)
{
	m_Enemy->Update(deltaTime);
	m_Enemy4->Update(deltaTime);
}

void PathState::onDraw(Renderer2D* m_2dRenderer)
{
	Grid::Instance()->DrawGrid(m_2dRenderer);
	m_Enemy->Draw(m_2dRenderer);
	m_Enemy4->Draw(m_2dRenderer);

	m_2dRenderer->setRenderColour(0.150, 0.150, 0.150, 1);
	m_2dRenderer->drawBox(127, 720, 200, 80);

	m_2dRenderer->setRenderColour(1, 1, 1, 1);
	m_2dRenderer->drawText(m_Font, "1. PATHFINDING", 40, 45);
	m_2dRenderer->drawText(m_Font2, " - PRESS SPACE BAR TO STOP AND START THE AI EXAMPLE.", 425, 55);
}