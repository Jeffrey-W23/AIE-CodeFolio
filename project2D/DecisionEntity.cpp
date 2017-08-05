#include "DecisionEntity.h"
#include "CollisionManager.h"
#include "MoveState.h"
#include "QWhatBehaviour.h"
#include "AFlee.h"
#include "ASeek.h"

DecisionEntity::DecisionEntity()
{
	// Create a collidable object for walls.
	CollisionManager* collider = CollisionManager::GetInstance();
	collider->AddObject(this);

	m_force = Vector2(10, 10);
	m_acceleration = Vector2(0, 0);
	m_velocity = Vector2(0, 0);
	m_position = Vector2(0, 0);
	SetPosition(Vector2(500, 360));

	// Set the type of object to wall
	this->SetType(ENEMY);

	// Question
	m_pRoot = new QWhatBehaviour();

	// Anwsers
	m_pRoot->m_pTrueDecision = new ASeek();
	m_pRoot->m_pFalseDecision = new AFlee();
}

DecisionEntity::~DecisionEntity()
{
	delete m_pRoot->m_pFalseDecision;
	delete m_pRoot->m_pTrueDecision;
	delete m_pRoot;
}

void DecisionEntity::Update(float deltaTime)
{
	m_pRoot->MakeDecision(this, deltaTime);
}

void DecisionEntity::Draw(Renderer2D* m_2dRenderer)
{
	m_2dRenderer->setRenderColour(0, 0, 1, 1);
	m_2dRenderer->drawSpriteTransformed3x3(nullptr, GlobalTrasform, 40, 40);
	m_2dRenderer->setRenderColour(0xFFFFFFFF);
}