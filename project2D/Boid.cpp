// #include, using, etc
#include "Boid.h"
#include "CollisionManager.h"
#include "FlockState.h"
#include <stdlib.h>

//--------------------------------------------------------------------------------------
// Default Constructor. Taking in a DynamicArray pointer of Boid pointers.
//--------------------------------------------------------------------------------------
Boid::Boid(DynamicArray<Boid*>* aEntityList)
{
	// Add the AI state and push it to the stack.
	m_AIStateMachine->AddState(0, new FlockState(aEntityList));
	m_AIStateMachine->PushState(0);

	// Create a collidable object for walls.
	CollisionManager* collider = CollisionManager::GetInstance();
	collider->AddObject(this);

	// set varaibles
	m_force = Vector2(10, 10);
	m_acceleration = Vector2(0, 0);
	m_velocity = Vector2(0, 0);
	SetPosition(Vector2(rand()%1200, rand()%700));

	// Set the type of object to wall
	this->SetType(ENEMY);
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
Boid::~Boid()
{
}

//--------------------------------------------------------------------------------------
// Update: A function to update objects.
//
// Param:
//		deltaTime: Pass in deltaTime. A number that updates per second.
//--------------------------------------------------------------------------------------
void Boid::Update(float deltaTime)
{
	// Update the AI Statemachine
	m_AIStateMachine->Update(deltaTime, this);

	// Loop the Entities back to the other side of the screen if they go off screen.
	if (GetPosition().x > 1270)
		SetPosition(Vector2(15, GetPosition().y));

	if (GetPosition().x < 10)
		SetPosition(Vector2(1265, GetPosition().y));

	if (GetPosition().y > 710)
		SetPosition(Vector2(GetPosition().x, 15));

	if (GetPosition().y < 10)
		SetPosition(Vector2(GetPosition().x, 705));
}

//--------------------------------------------------------------------------------------
// Draw: A function to render (or "draw") objects to the screen.
//
// Param:
//		renderer2D: a pointer to Renderer2D for rendering objects to screen.
//--------------------------------------------------------------------------------------
void Boid::Draw(Renderer2D* m_2dRenderer)
{
	// Draw the AI statemachine.
	m_AIStateMachine->Draw(m_2dRenderer);

	// Draw the Entity.
	m_2dRenderer->setRenderColour(1, 1, 0, 1);
	m_2dRenderer->drawSpriteTransformed3x3(nullptr, GlobalTrasform, 10, 10);
	m_2dRenderer->setRenderColour(0xFFFFFFFF);
}
