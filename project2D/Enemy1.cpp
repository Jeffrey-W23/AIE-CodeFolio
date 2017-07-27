#include "Enemy1.h"
#include "CollisionManager.h"
#include "MoveState.h"

Enemy1::Enemy1()
{
	m_AIStateMachine->AddState(0, new MoveState());
	m_AIStateMachine->PushState(0);

	// Create a collidable object for walls.
	CollisionManager* collider = CollisionManager::GetInstance();
	collider->AddObject(this);

	m_force = Vector2(10, 10);
	m_acceleration = Vector2(0, 0);
	m_velocity = Vector2(0, 0);
	m_position = Vector2(400, 400);

	SetPosition(Vector2(400, 400));

	// Set the type of object to wall
	this->SetType(ENEMY);
}

Enemy1::~Enemy1()
{
}

void Enemy1::Update(float deltaTime)
{
	m_AIStateMachine->Update(deltaTime, this);
}

void Enemy1::Draw(Renderer2D* m_2dRenderer)
{
	m_AIStateMachine->Draw(m_2dRenderer);

	m_2dRenderer->setRenderColour(1, 1, 0, 1);
	m_2dRenderer->drawSpriteTransformed3x3(nullptr, GlobalTrasform, 40, 40);
	m_2dRenderer->setRenderColour(0xFFFFFFFF);
}
