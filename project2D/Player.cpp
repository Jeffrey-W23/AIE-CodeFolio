// #include, using, etc
#include "Player.h"
#include "ControllerState.h"
#include "CollisionManager.h"

//--------------------------------------------------------------------------------------
// Default Constructor.
//--------------------------------------------------------------------------------------
Player::Player()
{
	// Add the AI state and push it to the stack.
	m_AIStateMachine->AddState(0, new ControllerState());
	m_AIStateMachine->PushState(0);

	// Create a collidable object for walls.
	CollisionManager* collider = CollisionManager::GetInstance();
	collider->AddObject(this);

	// set varaibles
	m_force = Vector2(10,10);
	m_acceleration = Vector2(0,0);
	m_velocity = Vector2(0,0);
	SetPosition(Vector2(500, 360));

	// Set the type of object to wall
	this->SetType(PLAYER);
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
Player::~Player()
{
}

//--------------------------------------------------------------------------------------
// Update: A function to update objects.
//
// Param:
//		deltaTime: Pass in deltaTime. A number that updates per second.
//--------------------------------------------------------------------------------------
void Player::Update(float deltaTime)
{
	// Update the AI Statemachine
	m_AIStateMachine->Update(deltaTime, this);
}

//--------------------------------------------------------------------------------------
// Draw: A function to render (or "draw") objects to the screen.
//
// Param:
//		renderer2D: a pointer to Renderer2D for rendering objects to screen.
//--------------------------------------------------------------------------------------
void Player::Draw(Renderer2D* m_2dRenderer)
{
	// Draw the AI statemachine.
	m_AIStateMachine->Draw(m_2dRenderer);

	// Draw the Entity.
	m_2dRenderer->drawSpriteTransformed3x3(nullptr, GlobalTrasform, 20, 20);
}