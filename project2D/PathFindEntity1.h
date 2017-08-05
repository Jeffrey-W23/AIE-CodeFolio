#pragma once
#include "Entity.h"

class PathFindEntity1 : public Entity
{
public:
	PathFindEntity1();
	~PathFindEntity1();

	void Update(float deltaTime);
	void Draw(Renderer2D* m_2dRenderer);
};