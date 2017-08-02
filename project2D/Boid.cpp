#include "Boid.h"
#include "CollisionManager.h"
#include "FlockState.h"
#include <stdlib.h>

Boid::Boid(DynamicArray<Boid*>* aEntityList)
{
	m_AIStateMachine->AddState(0, new FlockState(aEntityList));
	m_AIStateMachine->PushState(0);

	// Create a collidable object for walls.
	CollisionManager* collider = CollisionManager::GetInstance();
	collider->AddObject(this);

	m_force = Vector2(10, 10);
	m_acceleration = Vector2(0, 0);
	m_velocity = Vector2(0, 0);
	m_position = Vector2(400, 400);

	SetPosition(Vector2(rand()%1200, rand()%700));

	// Set the type of object to wall
	this->SetType(ENEMY);
}

Boid::~Boid()
{
}

void Boid::Update(float deltaTime)
{
	m_AIStateMachine->Update(deltaTime, this);

	if (GetPosition().x > 1270)
		SetPosition(Vector2(15, GetPosition().y));

	if (GetPosition().x < 10)
		SetPosition(Vector2(1265, GetPosition().y));

	if (GetPosition().y > 710)
		SetPosition(Vector2(GetPosition().x, 15));

	if (GetPosition().y < 10)
		SetPosition(Vector2(GetPosition().x, 705));
}

void Boid::Draw(Renderer2D* m_2dRenderer)
{
	m_AIStateMachine->Draw(m_2dRenderer);

	m_2dRenderer->setRenderColour(1, 1, 0, 1);
	m_2dRenderer->drawSpriteTransformed3x3(nullptr, GlobalTrasform, 10, 10);
	m_2dRenderer->setRenderColour(0xFFFFFFFF);
}
