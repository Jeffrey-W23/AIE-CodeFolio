#pragma once
#include "Entity.h"

class Enemy : public Entity
{
public:
	Enemy();
	~Enemy();

	void Update(float deltaTime);
	void Draw(Renderer2D* m_2dRenderer);
};