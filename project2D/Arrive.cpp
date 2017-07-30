#include "Arrive.h"
#include "Input.h"
#include "Entity.h"
using namespace aie;

Arrive::Arrive(float fWeighting, EDeceleration eDeceleration) : IBehaviour(fWeighting)
{
	m_eDeceleration = eDeceleration;
}

Arrive::~Arrive()
{
}

Vector2 Arrive::Update(Entity* pEntity, float deltaTime)
{
	// Calc target
	int nMouseX;
	int nMouseY;

	Input::getInstance()->getMouseXY(&nMouseX, &nMouseY);
	Vector2 v2MousePos(nMouseX, nMouseY);

	// calc arrive
	Vector2 v2Dir = v2MousePos - pEntity->GetPosition();
	double dist = v2Dir.magnitude();

	if (dist > 50)
	{
		const double DecelerationTweaker = 0.3;

		double speed = dist / ((double)m_eDeceleration * DecelerationTweaker);

		//Vector2().Min(speed, 100.0f);
		if (speed > 100)
			speed = 100;

		v2Dir * speed / dist;

		return (v2Dir * deltaTime);
	}

	return Vector2(0, 0);
}