#pragma once
#include "Entity.h"

class Player : public Entity
{
public:
	Player();
	~Player();

	void Update(float deltaTime);
	void Draw(Renderer2D* m_2dRenderer);
};