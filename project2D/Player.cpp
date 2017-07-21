#include "Player.h"
#include "Idle.h"
#include "Patrol.h"
#include "Controlled.h"

Player::Player()
{
	m_AIStateMachine = new AIStateMachine();

	m_AIStateMachine->AddState(0, new Idle());
	m_AIStateMachine->AddState(0, new Controlled());
	m_AIStateMachine->PushState(0);

	m_force = Vector2(10,10);
	m_acceleration = Vector2(0,0);
	m_velocity = Vector2(0,0);
}

Player::~Player()
{
	delete m_AIStateMachine;
}

void Player::Update(float deltaTime)
{
	m_AIStateMachine->Update(deltaTime, this);
}

void Player::Draw(Renderer2D* m_2dRenderer)
{
	m_AIStateMachine->Draw(m_2dRenderer);

	m_2dRenderer->drawBox(m_position.x, m_position.y, 20, 20);
}