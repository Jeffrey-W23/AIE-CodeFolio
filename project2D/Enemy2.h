#pragma once
#include "Entity.h"

class BaseQuestion;

class Enemy2 : public Entity
{
public:
	Enemy2();
	~Enemy2();

	void Update(float deltaTime);
	void Draw(Renderer2D* m_2dRenderer);

private:
	BaseQuestion* m_pRoot;
};