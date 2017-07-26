#pragma once
#include "IBehaviour.h"
#include "Vector2.h"

class KeyboardController : public IBehaviour
{
public:
	KeyboardController(float fWeighting);
	~KeyboardController();

	Vector2 Update(Entity* pEntity, float deltaTime);

protected:

	float speed;
	float mass;
	Vector2 direction;
};