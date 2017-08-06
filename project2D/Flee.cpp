// #include, using, etc
#include "Flee.h"
#include "Input.h"
#include "Entity.h"
using namespace aie;

//--------------------------------------------------------------------------------------
// Default Constructor. Taking in a float fWeighting and a bool for mouseflee or not.
//--------------------------------------------------------------------------------------
Flee::Flee(float fWeighting, bool bFleeMouse) : IBehaviour(fWeighting)
{
	// Set vars
	m_bFleeMouse = bFleeMouse;
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
Flee::~Flee()
{
}

//--------------------------------------------------------------------------------------
// Update: A virtual function from IBehaviour to update objects over time.
//
// Param:
//		deltaTime: Pass in deltaTime. A number that updates per second.
//		pEntity: a pointer to an entity.
//--------------------------------------------------------------------------------------
Vector2 Flee::Update(Entity* pEntity, float deltaTime)
{
	// Calc target
	int nMouseX;
	int nMouseY;
	Input::getInstance()->getMouseXY(&nMouseX, &nMouseY);
	Vector2 vPos;

	// Change flee target to mouse or flee point
	if (m_bFleeMouse)
		vPos = Vector2(nMouseX, nMouseY);
	else
		vPos = Vector2(1140, 360);

	Vector2 v2Dir = pEntity->GetPosition() - vPos;
	v2Dir.normalise();

	// return the weight of flee
	return v2Dir * 100.0f * deltaTime;
}