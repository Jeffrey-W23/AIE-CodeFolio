// #includes, using, etc
#include "BTAObAv.h"
#include "Vector2.h"
#include "ObstacleAvoidance.h"
#include "Arrive.h"
#include "Entity.h"
#include "Input.h"
using namespace aie;

//--------------------------------------------------------------------------------------
// Default Constructor.
//--------------------------------------------------------------------------------------
BTAObAv::BTAObAv()
{
	// Push ObstacleAvoidance Behaviour and Arrive to behaviours array.
	m_behaviours.PushBack(new ObstacleAvoidance(1.0f));
	m_behaviours.PushBack(new Arrive(0.5f, EDECELERATION_SLOW));
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
BTAObAv::~BTAObAv()
{
	for (unsigned i = 0; i < m_behaviours.Size(); ++i)
	{
		delete m_behaviours[i];
	}
}

//--------------------------------------------------------------------------------------
// Execute: A virtual function to update objects over time.
//
// Returns:
//		EBehaviourResult: An enum of success, fail or pending.
// Param:
//		deltaTime: Pass in deltaTime. A number that updates per second.
//		pEntity: A pointer to an entity.
//--------------------------------------------------------------------------------------
EBehaviourResult BTAObAv::Execute(Entity* pEntity, float deltaTime)
{
	Vector2 v2TotalForce;

	// Update each of the behaviours and apply the weight of other behaviours.
	for (unsigned int i = 0; i < m_behaviours.Size(); ++i)
	{
		Vector2 currentForce = m_behaviours[i]->Update(pEntity, deltaTime);
		currentForce = currentForce * m_behaviours[i]->m_fWeighting;
		v2TotalForce = v2TotalForce + currentForce;

		float fMagnitude = v2TotalForce.magnitude();

		if (fMagnitude > 150.0f)
		{
			v2TotalForce.normalise();
			v2TotalForce = v2TotalForce * 150.0f;
			break;
		}
	}

	// Set velocity
	Vector2 vel = pEntity->GetVelocity();
	vel += v2TotalForce;

	if (vel.magnitude() > 80)
	{
		vel.normalise();
		vel = vel * 80.0f;
	}

	// Set the position and velocity to the entity.
	pEntity->SetVelocity(vel);
	pEntity->SetPosition(pEntity->GetPosition() + vel * deltaTime);

	return EBHAVIOUR_SUCCESS;
}
