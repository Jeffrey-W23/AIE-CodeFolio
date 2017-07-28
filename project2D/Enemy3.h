#pragma once
#include "Entity.h"

class BTBaseNode;

class Enemy3 : public Entity
{
public:
	Enemy3();
	~Enemy3();

	void Update(float deltaTime);
	void Draw(Renderer2D* m_2dRenderer);

private:
	BTBaseNode* m_pRoot;
};