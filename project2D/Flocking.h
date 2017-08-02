#pragma once
#include "IBehaviour.h"
#include "DynamicArray.h"

class Boid;

class Flocking : public IBehaviour
{
public:
	Flocking(float fWeighting, DynamicArray<Boid*>* aEntityList);
	~Flocking();

	Vector2 ComputeAlignment(Entity* pEntity);
	Vector2 ComputeCohesion(Entity* pEntity);
	Vector2 ComputeSeparation(Entity* pEntity);
	Vector2 Update(Entity* pEntity, float deltaTime);

private:
	DynamicArray<Boid*>* m_aEntities;
};