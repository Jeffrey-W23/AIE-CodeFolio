// #include, using, etc
#include "FlockingState.h"
#include "Input.h"
#include "Boid.h"
#include "Grid.h"
#include "Font.h"

//--------------------------------------------------------------------------------------
// Default Constructor.
//--------------------------------------------------------------------------------------
FlockingState::FlockingState()
{
	// Create a new instances of the font.
	m_Font = new Font("./font/consolas.ttf", 50);
	m_Font2 = new Font("./font/consolas.ttf", 25);

	// Create new instance of the DynamicArray pointer of boids.
	m_Boids = new DynamicArray<Boid*>();

	// Push 30 boids to the array.
	for (int i = 0; i < 30; ++i)
	{
		m_Boids->PushBack(new Boid(m_Boids));
	}

}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
FlockingState::~FlockingState()
{
	// Delete each of the boids in the array.
	for (int i = 0; i < m_Boids->Size(); ++i)
	{
		delete (*m_Boids)[i];
	}

	delete m_Boids;
	delete m_Font;
	delete m_Font2;
}

//--------------------------------------------------------------------------------------
// onEnter: A virtual function from state that runs first when a state is loaded.
//
// Param:
//		pMachine: a pointer to StateMachine.
//--------------------------------------------------------------------------------------
void FlockingState::onEnter(StateMachine* pMachine)
{
}

//--------------------------------------------------------------------------------------
// onExit: A virtual function from state that runs on state exit.
//
// Param:
//		pMachine: a pointer to StateMachine.
//--------------------------------------------------------------------------------------
void FlockingState::onExit(StateMachine* pMachine)
{
}

//--------------------------------------------------------------------------------------
// onUpdate: A virtual function from state to update objects.
//
// Param:
//		deltaTime: Pass in deltaTime. A number that updates per second.
//		pMachine: a pointer to StateMachine.
//--------------------------------------------------------------------------------------
void FlockingState::onUpdate(float deltaTime, StateMachine* pMachine)
{
	for (int i = 0; i < m_Boids->Size(); ++i)
	{
		(*m_Boids)[i]->Update(deltaTime);
	}
}

//--------------------------------------------------------------------------------------
// onDraw: A virtual function from state to render (or "draw") objects to the screen.
//
// Param:
//		renderer2D: a pointer to Renderer2D for rendering objects to screen.
//--------------------------------------------------------------------------------------
void FlockingState::onDraw(Renderer2D* m_2dRenderer)
{
	// Draw each of the boids.
	for (int i = 0; i < m_Boids->Size(); ++i)
	{
		(*m_Boids)[i]->Draw(m_2dRenderer);
	}

	// Draw the instruction text.
	m_2dRenderer->setRenderColour(1, 1, 1, 1);
	m_2dRenderer->drawText(m_Font, "6. FLOCKING -", 40, 45);
	m_2dRenderer->drawText(m_Font2, "      FLOCKING BEHAVIOUR EXAMPLE.", 340, 70);
	m_2dRenderer->drawText(m_Font2, "      PRESS SPACE BAR TO STOP AND START THE AI EXAMPLE.", 340, 35);
}