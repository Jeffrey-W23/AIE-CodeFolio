#include "BehaviourEntity.h"
#include "CollisionManager.h"
#include "BTAObAv.h"
#include "BTQObAv.h"
#include "BTQStop.h"
#include "BTAStop.h"
#include "BTSelector.h"
#include "BTSequence.h"
#include "BTBaseNode.h"

BehaviourEntity::BehaviourEntity()
{
	// Create a collidable object for walls.
	CollisionManager* collider = CollisionManager::GetInstance();
	collider->AddObject(this);

	m_force = Vector2(10, 10);
	m_acceleration = Vector2(0, 0);
	m_velocity = Vector2(0, 0);
	m_position = Vector2(0, 0);
	SetPosition(Vector2(1000, 360));

	// Set the type of object to wall
	this->SetType(ENEMY);

	m_eBehType = EBEHAVIOURTYPE_STOP;
	m_bStop = true;

	m_pRoot = new BTSelector();

	BTBaseNode* pOAAnd = new BTSequence();
	BTBaseNode* pOAQ = new BTQObAv();
	BTBaseNode* pOAA = new BTAObAv();
	((BTComposite*)pOAAnd)->children.PushBack(pOAQ);
	((BTComposite*)pOAAnd)->children.PushBack(pOAA);

	BTBaseNode* pStopAnd = new BTSequence();
	BTBaseNode* pStopQ = new BTQStop();
	BTBaseNode* pStopA = new BTAStop();
	((BTComposite*)pStopAnd)->children.PushBack(pStopQ);
	((BTComposite*)pStopAnd)->children.PushBack(pStopA);

	((BTComposite*)m_pRoot)->children.PushBack(pOAAnd);
	((BTComposite*)m_pRoot)->children.PushBack(pStopAnd);
}

BehaviourEntity::~BehaviourEntity()
{
	delete m_pRoot;
}

void BehaviourEntity::Update(float deltaTime)
{
	if (Input::getInstance()->wasKeyPressed(aie::INPUT_KEY_SPACE))
	{
		m_bStop = !m_bStop;
	}

	if (m_bStop)
		m_eBehType = EBEHAVIOURTYPE_STOP;
	
	else
	{
		m_eBehType = EBEHAVIOURTYPE_OA;
	}

	m_pRoot->Execute(this, deltaTime);
}

void BehaviourEntity::Draw(Renderer2D* m_2dRenderer)
{
	m_2dRenderer->setRenderColour(0, 1, 0, 1);
	m_2dRenderer->drawSpriteTransformed3x3(nullptr, GlobalTrasform, 15, 15);
	m_2dRenderer->setRenderColour(0xFFFFFFFF);
}