#pragma once
#include "Vector2.h"
#include "IBehaviour.h"

class Seek : public IBehaviour
{
public:
	Seek();
	~Seek();

	void Update(BaseAgent* agent, float deltaTime);

protected:

	Vector2* m_targetPos;
};