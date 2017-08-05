#include "PathFindEntity2.h"
#include "IdleState.h"
#include "FollowState.h"
#include "CollisionManager.h"

PathFindEntity2::PathFindEntity2()
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
	SetPosition(Vector2(450, 550));

	// Set the type of object to wall
	this->SetType(ENEMY);
}

PathFindEntity2::~PathFindEntity2()
{
}

void PathFindEntity2::Update(float deltaTime)
{
	m_AIStateMachine->Update(deltaTime, this);
}

void PathFindEntity2::Draw(Renderer2D* m_2dRenderer)
{
	m_AIStateMachine->Draw(m_2dRenderer);

	m_2dRenderer->setRenderColour(1, 0, 1, 1);
	m_2dRenderer->drawSpriteTransformed3x3(nullptr, GlobalTrasform, 40, 40);
	m_2dRenderer->setRenderColour(0xFFFFFFFF);
}