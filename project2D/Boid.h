#pragma once
#include "Entity.h"

class Boid : public Entity
{
public:
	Boid(DynamicArray<Boid*>* aEntityList);
	~Boid();

	void Update(float deltaTime);
	void Draw(Renderer2D* m_2dRenderer);
};