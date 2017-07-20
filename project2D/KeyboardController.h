#pragma once
#include "IBehaviour.h"
#include "Vector2.h"

class KeyboardController : public IBehaviour
{
public:
	KeyboardController();
	~KeyboardController();

	void Update(BaseAgent* agent, float deltaTime);

protected:

	float speed;
	float mass;
	Vector2 direction;
};