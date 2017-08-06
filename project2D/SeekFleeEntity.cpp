// #include, using, etc
#include "SeekFleeEntity.h"
#include "CollisionManager.h"
#include "MoveState.h"

//--------------------------------------------------------------------------------------
// Default Constructor.
//--------------------------------------------------------------------------------------
SeekFleeEntity::SeekFleeEntity()
{
	// Add the AI state and push it to the stack.
	m_AIStateMachine->AddState(0, new MoveState());
	m_AIStateMachine->PushState(0);

	// Create a collidable object for entity.
	CollisionManager* collider = CollisionManager::GetInstance();
	collider->AddObject(this);

	// set varaibles
	m_force = Vector2(10, 10);
	m_acceleration = Vector2(0, 0);
	m_velocity = Vector2(0, 0);
	SetPosition(Vector2(500, 360));

	// Set the type of object to wall
	this->SetType(ENEMY);
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
SeekFleeEntity::~SeekFleeEntity()
{
}

//--------------------------------------------------------------------------------------
// Update: A function to update objects.
//
// Param:
//		deltaTime: Pass in deltaTime. A number that updates per second.
//--------------------------------------------------------------------------------------
void SeekFleeEntity::Update(float deltaTime)
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
void SeekFleeEntity::Draw(Renderer2D* m_2dRenderer)
{
	// Draw the AI statemachine.
	m_AIStateMachine->Draw(m_2dRenderer);

	// Draw the Entity.
	m_2dRenderer->setRenderColour(1, 1, 0, 1);
	m_2dRenderer->drawSpriteTransformed3x3(nullptr, GlobalTrasform, 40, 40);
	m_2dRenderer->setRenderColour(0xFFFFFFFF);
}
