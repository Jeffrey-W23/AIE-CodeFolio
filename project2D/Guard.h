#pragma once
#include "BaseAgent.h"

class Guard : public BaseAgent
{
public:
	Guard();
	~Guard();

	void Update(float deltaTime);
	void Draw(Renderer2D* m_2dRenderer);
};

