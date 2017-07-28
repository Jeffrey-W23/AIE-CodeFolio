#include "BTASeek.h"
#include "Vector2.h"
#include "Seek.h"
#include "Entity.h"
#include "Input.h"
using namespace aie;

BTASeek::BTASeek()
{
	m_behaviours.PushBack(new Seek(1.0f));
}

BTASeek::~BTASeek()
{
	for (unsigned i = 0; i < m_behaviours.Size(); ++i)
	{
		delete m_behaviours[i];
	}
}

EBehaviourResult BTASeek::Execute(Entity* pEntity, float deltaTime)
{
	Vector2 v2TotalForce;

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

	pEntity->SetPosition(pEntity->GetPosition() + v2TotalForce);

	return EBHAVIOUR_SUCCESS;
}