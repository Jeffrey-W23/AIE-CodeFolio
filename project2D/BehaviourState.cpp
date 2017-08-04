#include "BehaviourState.h"
#include "Input.h"
#include "Enemy3.h"
#include "Grid.h"
#include "OAMap.h"
#include "Font.h"

BehaviourState::BehaviourState()
{
	m_Enemy3 = new Enemy3();
	m_Font = new Font("./font/consolas.ttf", 50);
	m_Font2 = new Font("./font/consolas.ttf", 25);
}

BehaviourState::~BehaviourState()
{
	delete m_Enemy3;
}

void BehaviourState::onEnter(StateMachine* pMachine)
{
}

void BehaviourState::onExit(StateMachine* pMachine)
{

}

void BehaviourState::onUpdate(float deltaTime, StateMachine* pMachine)
{
	m_Enemy3->Update(deltaTime);
}

void BehaviourState::onDraw(Renderer2D* m_2dRenderer)
{
	OAMap::Instance()->Draw(m_2dRenderer);
	m_Enemy3->Draw(m_2dRenderer);

	m_2dRenderer->setRenderColour(1, 1, 1, 1);
	m_2dRenderer->drawText(m_Font, "5. BEHAVIORTREE", 40, 45);
	m_2dRenderer->drawText(m_Font2, " - PRESS SPACE BAR TO STOP AND START THE AI EXAMPLE.", 450, 55);
}