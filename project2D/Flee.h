#pragma once
#include "IBehaviour.h"

class Flee : public IBehaviour
{
public:
	Flee(float fWeighting, bool bMouseFlee);
	~Flee();

	Vector2 Update(Entity* pEntity, float deltaTime);
	
private:
	bool m_bFleeMouse;
};

