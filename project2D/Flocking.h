#pragma once
#include "IBehaviour.h"

class Flocking : public IBehaviour
{
public:
	Flocking(float fWeighting);
	~Flocking();

	Vector2 ComputeAlignment(Entity* pEntity, DynamicArray<Entity*> Entities);
	Vector2 ComputeCohesion(Entity* pEntity, DynamicArray<Entity*> Entities);
	Vector2 ComputeSeparation(Entity* pEntity, DynamicArray<Entity*> Entities);
	Vector2 Update(Entity* pEntity, float deltaTime);
};