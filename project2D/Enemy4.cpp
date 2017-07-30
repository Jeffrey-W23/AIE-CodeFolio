#include "Enemy4.h"
#include "IdleState.h"
#include "FollowState.h"
#include "CollisionManager.h"

Enemy4::Enemy4()
{
	// Create a collidable object for walls.
	CollisionManager* collider = CollisionManager::GetInstance();
	collider->AddObject(this);

	m_AIStateMachine->AddState(0, new IdleState());
	m_AIStateMachine->AddState(1, new FollowState(81, 18));
	m_AIStateMachine->PushState(0);

	m_force = Vector2(10, 10);
	m_acceleration = Vector2(0, 0);
	m_velocity = Vector2(0, 0);
	SetPosition(Vector2(200, 550));

	// Set the type of object to wall
	this->SetType(ENEMY);
}

Enemy4::~Enemy4()
{
}

void Enemy4::Update(float deltaTime)
{
	m_AIStateMachine->Update(deltaTime, this);
}

void Enemy4::Draw(Renderer2D* m_2dRenderer)
{
	m_AIStateMachine->Draw(m_2dRenderer);

	m_2dRenderer->setRenderColour(1, 0, 1, 1);
	m_2dRenderer->drawSpriteTransformed3x3(nullptr, GlobalTrasform, 40, 40);
	m_2dRenderer->setRenderColour(0xFFFFFFFF);
}