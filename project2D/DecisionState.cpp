#include "DecisionState.h"
#include "Input.h"
#include "Enemy2.h"
#include "Grid.h"
#include "Font.h"

DecisionState::DecisionState()
{
	m_Enemy2 = new Enemy2();
	m_Font = new Font("./font/consolas.ttf", 50);
	m_Font2 = new Font("./font/consolas.ttf", 25);
}

DecisionState::~DecisionState()
{
	delete m_Enemy2;
}

void DecisionState::onEnter(StateMachine* pMachine)
{
}

void DecisionState::onExit(StateMachine* pMachine)
{

}

void DecisionState::onUpdate(float deltaTime, StateMachine* pMachine)
{
	m_Enemy2->Update(deltaTime);
}

void DecisionState::onDraw(Renderer2D* m_2dRenderer)
{
	m_Enemy2->Draw(m_2dRenderer);

	m_2dRenderer->setRenderColour(1, 1, 1, 1);
	m_2dRenderer->drawText(m_Font, "4. DECISIONTREE", 40, 45);
	m_2dRenderer->drawText(m_Font2, " - PRESS SPACE BAR TO STOP AND START THE AI EXAMPLE.", 450, 55);
}