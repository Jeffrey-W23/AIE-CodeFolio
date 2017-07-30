#pragma once
#include "Entity.h"

class Enemy4 : public Entity
{
public:
	Enemy4();
	~Enemy4();

	void Update(float deltaTime);
	void Draw(Renderer2D* m_2dRenderer);
};