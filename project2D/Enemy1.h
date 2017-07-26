#pragma once
#include "Entity.h"

class Enemy1 : public Entity
{
public:
	Enemy1();
	~Enemy1();

	void Update(float deltaTime);
	void Draw(Renderer2D* m_2dRenderer);
};