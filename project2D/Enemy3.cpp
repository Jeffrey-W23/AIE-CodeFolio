#include "Enemy3.h"
#include "CollisionManager.h"
#include "BTASeek.h"
#include "BTAFlee.h"
#include "BTQSeek.h"
#include "BTQFlee.h"
#include "BTQStop.h"
#include "BTAStop.h"
#include "BTSelector.h"
#include "BTSequence.h"
#include "BTBaseNode.h"

Enemy3::Enemy3()
{
	// Create a collidable object for walls.
	CollisionManager* collider = CollisionManager::GetInstance();
	collider->AddObject(this);

	m_force = Vector2(10, 10);
	m_acceleration = Vector2(0, 0);
	m_velocity = Vector2(0, 0);
	m_position = Vector2(0, 0);
	SetPosition(Vector2(1000, 500));

	// Set the type of object to wall
	this->SetType(ENEMY);

	m_pRoot = new BTSelector();

	BTBaseNode* pSeekAnd = new BTSequence();
	BTBaseNode* pSeekQ = new BTQSeek();
	BTBaseNode* pSeekA = new BTASeek();
	((BTComposite*)pSeekAnd)->children.PushBack(pSeekQ);
	((BTComposite*)pSeekAnd)->children.PushBack(pSeekA);

	BTBaseNode* pFleeAnd = new BTSequence();
	BTBaseNode* pFleeQ = new BTQFlee();
	BTBaseNode* pFleeA = new BTAFlee();
	((BTComposite*)pFleeAnd)->children.PushBack(pFleeQ);
	((BTComposite*)pFleeAnd)->children.PushBack(pFleeA);

	BTBaseNode* pStopAnd = new BTSequence();
	BTBaseNode* pStopQ = new BTQStop();
	BTBaseNode* pStopA = new BTAStop();
	((BTComposite*)pStopAnd)->children.PushBack(pStopQ);
	((BTComposite*)pStopAnd)->children.PushBack(pStopA);

	((BTComposite*)m_pRoot)->children.PushBack(pSeekAnd);
	((BTComposite*)m_pRoot)->children.PushBack(pFleeAnd);
	((BTComposite*)m_pRoot)->children.PushBack(pStopAnd);
}

Enemy3::~Enemy3()
{
	/*delete pStop;
	delete pSeek;	// OUT OF SCOPE?
	delete pFlee;*/
	delete m_pRoot;
}

void Enemy3::Update(float deltaTime)
{
	m_pRoot->Execute(this, deltaTime);
}

void Enemy3::Draw(Renderer2D* m_2dRenderer)
{
	m_2dRenderer->setRenderColour(0, 1, 0, 1);
	m_2dRenderer->drawSpriteTransformed3x3(nullptr, GlobalTrasform, 35, 35);
	m_2dRenderer->setRenderColour(0xFFFFFFFF);
}