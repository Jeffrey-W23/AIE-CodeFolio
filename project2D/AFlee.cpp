// #include, using, etc
#include "AFlee.h"
#include <iostream>
#include "Flee.h"
#include "Entity.h"
using namespace std;

//--------------------------------------------------------------------------------------
// Default Constructor.
//--------------------------------------------------------------------------------------
AFlee::AFlee()
{
	// Push Flee Behaviour to behaviours array.
	m_behaviours.PushBack(new Flee(1.0f, true));
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
AFlee::~AFlee()
{
	for (unsigned i = 0; i < m_behaviours.Size(); ++i)
	{
		delete m_behaviours[i];
	}
}

//--------------------------------------------------------------------------------------
// MakeDecision: A virtual function to update objects over time.
//
// Param:
//		deltaTime: Pass in deltaTime. A number that updates per second.
//		pEntity: a pointer to the entity.
//--------------------------------------------------------------------------------------
void AFlee::MakeDecision(Entity* pEntity, float deltaTime)
{
	Vector2 v2TotalForce;

	// Update each of the behaviours and apply the weight of other behaviours.
	for (unsigned int i = 0; i < m_behaviours.Size(); ++i)
	{
		Vector2 currentForce = m_behaviours[i]->Update(pEntity, deltaTime);
		currentForce = currentForce * m_behaviours[i]->m_fWeighting;
		v2TotalForce = v2TotalForce + currentForce;

		float fMagnitude = v2TotalForce.magnitude();

		if (fMagnitude > 10.0f)
		{
			v2TotalForce.normalise();
			v2TotalForce = v2TotalForce * 10.0f;
			break;
		}
	}

	// Set the position and velocity to the entity.
	pEntity->SetVelocity(v2TotalForce);
	pEntity->SetPosition(pEntity->GetPosition() + v2TotalForce);
}
