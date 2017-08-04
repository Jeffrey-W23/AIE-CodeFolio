#include "FlockingState.h"
#include "Input.h"
#include "Boid.h"
#include "Grid.h"
#include "Font.h"

FlockingState::FlockingState()
{
	m_Font = new Font("./font/consolas.ttf", 50); // delete fonts on all states
	m_Font2 = new Font("./font/consolas.ttf", 25); // delete fonts on all states

	m_Boids = new DynamicArray<Boid*>();

	for (int i = 0; i < 30; ++i)
	{
		m_Boids->PushBack(new Boid(m_Boids));
	}

}

FlockingState::~FlockingState()
{
	for (int i = 0; i < m_Boids->Size(); ++i)
	{
		delete (*m_Boids)[i];
	}

	delete m_Boids;
}

void FlockingState::onEnter(StateMachine* pMachine)
{
}

void FlockingState::onExit(StateMachine* pMachine)
{

}

void FlockingState::onUpdate(float deltaTime, StateMachine* pMachine)
{
	for (int i = 0; i < m_Boids->Size(); ++i)
	{
		(*m_Boids)[i]->Update(deltaTime);
	}
}

void FlockingState::onDraw(Renderer2D* m_2dRenderer)
{
	for (int i = 0; i < m_Boids->Size(); ++i)
	{
		(*m_Boids)[i]->Draw(m_2dRenderer);
	}

	m_2dRenderer->setRenderColour(1, 1, 1, 1);
	m_2dRenderer->drawText(m_Font, "6. FLOCKING", 40, 45);
	m_2dRenderer->drawText(m_Font2, " - PRESS SPACE BAR TO STOP AND START THE AI EXAMPLE.", 340, 55);
}