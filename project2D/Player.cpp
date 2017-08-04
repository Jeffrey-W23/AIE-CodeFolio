#include "Player.h"
#include "ControllerState.h"
#include "CollisionManager.h"

Player::Player()
{
	// Create a collidable object for walls.
	CollisionManager* collider = CollisionManager::GetInstance();
	collider->AddObject(this);

	m_AIStateMachine->AddState(0, new ControllerState());
	m_AIStateMachine->PushState(0);

	m_force = Vector2(10,10);
	m_acceleration = Vector2(0,0);
	m_velocity = Vector2(0,0);
	m_position = Vector2(0, 0);

	SetPosition(Vector2(500, 360));

	// Set the type of object to wall
	this->SetType(PLAYER);
}

Player::~Player()
{
}

void Player::Update(float deltaTime)
{
	m_AIStateMachine->Update(deltaTime, this);
}

void Player::Draw(Renderer2D* m_2dRenderer)
{
	m_AIStateMachine->Draw(m_2dRenderer);

	m_2dRenderer->drawSpriteTransformed3x3(nullptr, GlobalTrasform, 20, 20);
}