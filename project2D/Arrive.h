#pragma once
#include "IBehaviour.h"

enum EDeceleration
{
	EDECELERATION_SLOW = 3,
	EDECELERATION_NORMAL = 2,
	EDECELERATION_FAST = 1
};

class Arrive : public IBehaviour
{
public:
	Arrive(float fWeighting, EDeceleration eDeceleration);
	~Arrive();

	Vector2 Update(Entity* pEntity, float deltaTime);

private:
	EDeceleration m_eDeceleration;
};