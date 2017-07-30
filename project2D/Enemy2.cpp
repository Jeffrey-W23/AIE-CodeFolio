#include "Enemy2.h"
#include "CollisionManager.h"
#include "MoveState.h"
#include "QWhatBehaviour.h"
#include "AFlee.h"
#include "ASeek.h"

Enemy2::Enemy2()
{
	// Create a collidable object for walls.
	CollisionManager* collider = CollisionManager::GetInstance();
	collider->AddObject(this);

	m_force = Vector2(10, 10);
	m_acceleration = Vector2(0, 0);
	m_velocity = Vector2(0, 0);
	m_position = Vector2(0, 0);
	SetPosition(Vector2(900,500));

	// Set the type of object to wall
	this->SetType(ENEMY);

	// Question
	m_pRoot = new QWhatBehaviour();

	// Anwsers
	m_pRoot->m_pTrueDecision = new ASeek();
	m_pRoot->m_pFalseDecision = new AFlee();
}

Enemy2::~Enemy2()
{
	delete m_pRoot->m_pFalseDecision;
	delete m_pRoot->m_pTrueDecision;
	delete m_pRoot;
}

void Enemy2::Update(float deltaTime)
{
	m_pRoot->MakeDecision(this, deltaTime);
}

void Enemy2::Draw(Renderer2D* m_2dRenderer)
{
	m_2dRenderer->setRenderColour(0, 0, 1, 1);
	m_2dRenderer->drawSpriteTransformed3x3(nullptr, GlobalTrasform, 40, 40);
	m_2dRenderer->setRenderColour(0xFFFFFFFF);
}