// #include, using, etc
#include "Arrive.h"
#include "Input.h"
#include "Entity.h"
using namespace aie;

//--------------------------------------------------------------------------------------
// Default Constructor. Taking in a float fWeighting.
//--------------------------------------------------------------------------------------
Arrive::Arrive(float fWeighting, EDeceleration eDeceleration) : IBehaviour(fWeighting)
{
	m_eDeceleration = eDeceleration;
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
Arrive::~Arrive()
{
}

//--------------------------------------------------------------------------------------
// Update: A virtual function from IBehaviour to update objects over time.
//
// Param:
//		deltaTime: Pass in deltaTime. A number that updates per second.
//		pEntity: a pointer to an entity.
//--------------------------------------------------------------------------------------
Vector2 Arrive::Update(Entity* pEntity, float deltaTime)
{
	// Calc target
	int nMouseX;
	int nMouseY;
	Input::getInstance()->getMouseXY(&nMouseX, &nMouseY);
	Vector2 v2MousePos(nMouseX, nMouseY);

	// Calc arrive
	Vector2 v2Dir = v2MousePos - pEntity->GetPosition();
	double dist = v2Dir.magnitude();

	if (dist > 0)
	{
		const double DecelerationTweaker = 0.3;

		double speed = dist / ((double)m_eDeceleration * DecelerationTweaker);

		if (speed > 100)
			speed = 100;

		Vector2 v2DesiredVel = v2Dir * speed / dist;

		return (v2DesiredVel - pEntity->GetVelocity());
	}

	return Vector2(0, 0);
}