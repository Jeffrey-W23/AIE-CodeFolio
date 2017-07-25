#include "Enemy.h"
#include "Idle.h"
#include "Patrol.h"
#include "CollisionManager.h"

Enemy::Enemy()
{
	// Create a collidable object for walls.
	CollisionManager* collider = CollisionManager::GetInstance();
	collider->AddObject(this);

	m_AIStateMachine->AddState(0, new Idle());
	m_AIStateMachine->AddState(1, new Patrol());
	m_AIStateMachine->PushState(0);

	m_force = Vector2(10, 10);
	m_acceleration = Vector2(0, 0);
	m_velocity = Vector2(0, 0);
	m_position = Vector2(0, 0);

	// Set the type of object to wall
	this->SetType(PLAYER);
}

Enemy::~Enemy()
{
}

void Enemy::Update(float deltaTime)
{
	m_AIStateMachine->Update(deltaTime, this);
}

void Enemy::Draw(Renderer2D* m_2dRenderer)
{
	m_AIStateMachine->Draw(m_2dRenderer);

	m_2dRenderer->setRenderColour(1, 1, 0, 1);
	m_2dRenderer->drawSpriteTransformed3x3(nullptr, GlobalTrasform, 40, 40);
	m_2dRenderer->setRenderColour(0xFFFFFFFF);
}