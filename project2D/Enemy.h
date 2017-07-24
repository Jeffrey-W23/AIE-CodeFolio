#pragma once
#include "BaseAgent.h"

class Enemy : public BaseAgent
{
public:
	Enemy();
	~Enemy();

	void Update(float deltaTime);
	void Draw(Renderer2D* m_2dRenderer);
};