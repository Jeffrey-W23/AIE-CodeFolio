#include "Player.h"
#include "Idle.h"
#include "Patrol.h"
#include "Controlled.h"
#include "KeyboardController.h"

Player::Player()
{
	m_StateMachine = new StateMachine();

	m_StateMachine->AddState(0, new Controlled(this));
	m_StateMachine->PushState(0);

	m_force = Vector2(10,10);
	m_acceleration = Vector2(0,0);
	m_velocity = Vector2(0,0);

	/*m_controller = new KeyboardController();
	m_behaviours.PushBack(m_controller);*/
}

Player::~Player()
{
	delete m_StateMachine;
}

void Player::Update(float deltaTime)
{
	m_StateMachine->Update(deltaTime);

	/*for (int i = 0; i < m_behaviours.Size(); ++i)
		m_behaviours[i]->Update(this, deltaTime);*/
}

void Player::Draw(Renderer2D* m_2dRenderer)
{
	m_StateMachine->Draw(m_2dRenderer);

	m_2dRenderer->drawBox(m_position.x, m_position.y, 20, 20);
}