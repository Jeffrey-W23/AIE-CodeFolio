#pragma once
#include "IBehaviour.h"

class Seek : public IBehaviour
{
public:
	Seek(float fWeighting);
	~Seek();

	Vector2 Update(Entity* pEntity, float deltaTime);
};

