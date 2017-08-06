// #include, using, etc
#include "BehaviourEntity.h"
#include "CollisionManager.h"
#include "BTAObAv.h"
#include "BTQObAv.h"
#include "BTQStop.h"
#include "BTAStop.h"
#include "BTSelector.h"
#include "BTSequence.h"
#include "BTBaseNode.h"

//--------------------------------------------------------------------------------------
// Default Constructor.
//--------------------------------------------------------------------------------------
BehaviourEntity::BehaviourEntity()
{
	// Create a collidable object for walls.
	CollisionManager* collider = CollisionManager::GetInstance();
	collider->AddObject(this);

	// set varaibles
	m_force = Vector2(10, 10);
	m_acceleration = Vector2(0, 0);
	m_velocity = Vector2(0, 0);
	SetPosition(Vector2(1000, 360));

	// Start the entity stopped.
	m_eBehType = EBEHAVIOURTYPE_STOP;
	m_bStop = true;

	// Set the type of object to wall
	this->SetType(ENEMY);

	//--------------------------------------------------
	// Set up the Behaviour tree
	//--------------------------------------------------
	// New selector // OR
	m_pRoot = new BTSelector();

	// New Sequence // AND
	BTBaseNode* pOAAnd = new BTSequence();
	BTBaseNode* pOAQ = new BTQObAv();
	BTBaseNode* pOAA = new BTAObAv();
	((BTComposite*)pOAAnd)->children.PushBack(pOAQ);
	((BTComposite*)pOAAnd)->children.PushBack(pOAA);

	// New Sequence // AND
	BTBaseNode* pStopAnd = new BTSequence();
	BTBaseNode* pStopQ = new BTQStop();
	BTBaseNode* pStopA = new BTAStop();
	((BTComposite*)pStopAnd)->children.PushBack(pStopQ);
	((BTComposite*)pStopAnd)->children.PushBack(pStopA);

	// Push OAAnd and StopAnd to the tree
	((BTComposite*)m_pRoot)->children.PushBack(pOAAnd);
	((BTComposite*)m_pRoot)->children.PushBack(pStopAnd);
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
BehaviourEntity::~BehaviourEntity()
{
	delete m_pRoot;
}

//--------------------------------------------------------------------------------------
// Update: A function to update objects.
//
// Param:
//		deltaTime: Pass in deltaTime. A number that updates per second.
//--------------------------------------------------------------------------------------
void BehaviourEntity::Update(float deltaTime)
{
	// Stop and start the entity.
	if (Input::getInstance()->wasKeyPressed(aie::INPUT_KEY_SPACE))
		m_bStop = !m_bStop;

	if (m_bStop)
		m_eBehType = EBEHAVIOURTYPE_STOP;
	else
		m_eBehType = EBEHAVIOURTYPE_OA;

	// Update the behaviour tree
	m_pRoot->Execute(this, deltaTime);
}

//--------------------------------------------------------------------------------------
// Draw: A function to render (or "draw") objects to the screen.
//
// Param:
//		renderer2D: a pointer to Renderer2D for rendering objects to screen.
//--------------------------------------------------------------------------------------
void BehaviourEntity::Draw(Renderer2D* m_2dRenderer)
{
	// Draw the Entity.
	m_2dRenderer->setRenderColour(0, 1, 0, 1);
	m_2dRenderer->drawSpriteTransformed3x3(nullptr, GlobalTrasform, 15, 15);
	m_2dRenderer->setRenderColour(0xFFFFFFFF);
}