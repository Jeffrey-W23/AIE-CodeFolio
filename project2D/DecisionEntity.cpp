// #include, using, etc
#include "DecisionEntity.h"
#include "CollisionManager.h"
#include "MoveState.h"
#include "QWhatBehaviour.h"
#include "AFlee.h"
#include "ASeek.h"

//--------------------------------------------------------------------------------------
// Default Constructor.
//--------------------------------------------------------------------------------------
DecisionEntity::DecisionEntity()
{
	// Create a collidable object for walls.
	CollisionManager* collider = CollisionManager::GetInstance();
	collider->AddObject(this);

	// set varaibles
	m_force = Vector2(10, 10);
	m_acceleration = Vector2(0, 0);
	m_velocity = Vector2(0, 0);
	SetPosition(Vector2(500, 360));

	// Set the type of object to wall
	this->SetType(ENEMY);

	// Questions
	m_pRoot = new QWhatBehaviour();

	// Anwsers
	m_pRoot->m_pTrueDecision = new ASeek();
	m_pRoot->m_pFalseDecision = new AFlee();
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
DecisionEntity::~DecisionEntity()
{
	delete m_pRoot->m_pFalseDecision;
	delete m_pRoot->m_pTrueDecision;
	delete m_pRoot;
}

//--------------------------------------------------------------------------------------
// Update: A function to update objects.
//
// Param:
//		deltaTime: Pass in deltaTime. A number that updates per second.
//--------------------------------------------------------------------------------------
void DecisionEntity::Update(float deltaTime)
{
	// Update the decision tree.
	m_pRoot->MakeDecision(this, deltaTime);
}

//--------------------------------------------------------------------------------------
// Draw: A function to render (or "draw") objects to the screen.
//
// Param:
//		renderer2D: a pointer to Renderer2D for rendering objects to screen.
//--------------------------------------------------------------------------------------
void DecisionEntity::Draw(Renderer2D* m_2dRenderer)
{
	// Draw the Entity.
	m_2dRenderer->setRenderColour(0, 0, 1, 1);
	m_2dRenderer->drawSpriteTransformed3x3(nullptr, GlobalTrasform, 40, 40);
	m_2dRenderer->setRenderColour(0xFFFFFFFF);
}