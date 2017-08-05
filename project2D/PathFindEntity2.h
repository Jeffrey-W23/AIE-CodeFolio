#pragma once
#include "Entity.h"

class PathFindEntity2 : public Entity
{
public:
	PathFindEntity2();
	~PathFindEntity2();

	void Update(float deltaTime);
	void Draw(Renderer2D* m_2dRenderer);
};