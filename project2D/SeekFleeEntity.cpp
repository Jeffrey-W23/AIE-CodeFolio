#include "SeekFleeEntity.h"
#include "CollisionManager.h"
#include "MoveState.h"

SeekFleeEntity::SeekFleeEntity()
{
	m_AIStateMachine->AddState(0, new MoveState());
	m_AIStateMachine->PushState(0);

	// Create a collidable object for walls.
	CollisionManager* collider = CollisionManager::GetInstance();
	collider->AddObject(this);

	m_force = Vector2(10, 10);
	m_acceleration = Vector2(0, 0);
	m_velocity = Vector2(0, 0);
	SetPosition(Vector2(500, 360));

	// Set the type of object to wall
	this->SetType(ENEMY);
}

SeekFleeEntity::~SeekFleeEntity()
{
}

void SeekFleeEntity::Update(float deltaTime)
{
	m_AIStateMachine->Update(deltaTime, this);
}

void SeekFleeEntity::Draw(Renderer2D* m_2dRenderer)
{
	m_AIStateMachine->Draw(m_2dRenderer);

	m_2dRenderer->setRenderColour(1, 1, 0, 1);
	m_2dRenderer->drawSpriteTransformed3x3(nullptr, GlobalTrasform, 40, 40);
	m_2dRenderer->setRenderColour(0xFFFFFFFF);
}
