#include "Flocking.h"
#include "Input.h"
#include "Entity.h"
using namespace aie;

Flocking::Flocking(float fWeighting) : IBehaviour(fWeighting)
{
}

Flocking::~Flocking()
{
}

Vector2 Flocking::ComputeAlignment(Entity* pEntity, DynamicArray<Entity*> Entities)
{
	Vector2 v2Point;
	int nNeighborCount = 0;

	for (int i = 0; i < Entities.Size(); ++i)
	{
		if (Entities[i] != pEntity)
		{
			if (Vector2::Distance(Entities[i]->GetPosition(), pEntity->GetPosition()) < 300)
			{
				v2Point.x += Entities[i]->GetVelocity().x;
				v2Point.y += Entities[i]->GetVelocity().y;
				nNeighborCount++;
			}
		}
	}

	if (nNeighborCount == 0)
		return v2Point;

	v2Point.x /= nNeighborCount;
	v2Point.y /= nNeighborCount;
	v2Point.normalise();

	return v2Point;
}

Vector2 Flocking::ComputeCohesion(Entity* pEntity, DynamicArray<Entity*> Entities)
{
	Vector2 v2Point;
	int nNeighborCount = 0;

	for (int i = 0; i < Entities.Size(); ++i)
	{
		if (Entities[i] != pEntity)
		{
			if (Vector2::Distance(Entities[i]->GetPosition(), pEntity->GetPosition()) < 300)
			{
				v2Point.x += Entities[i]->GetPosition().x;
				v2Point.y += Entities[i]->GetPosition().y;
				nNeighborCount++;
			}
		}
	}

	if (nNeighborCount == 0)
		return v2Point;

	v2Point.x /= nNeighborCount;
	v2Point.y /= nNeighborCount;
	v2Point.x -= pEntity->GetPosition().x;
	v2Point.y -= pEntity->GetPosition().y;
	v2Point.normalise();

	return v2Point;
}

Vector2 Flocking::ComputeSeparation(Entity* pEntity, DynamicArray<Entity*> Entities)
{
	Vector2 v2Point;
	int nNeighborCount = 0;

	for (int i = 0; i < Entities.Size(); ++i)
	{
		if (Entities[i] != pEntity)
		{
			if (Vector2::Distance(Entities[i]->GetPosition(), pEntity->GetPosition()) < 300)
			{
				v2Point.x += Entities[i]->GetPosition().x - pEntity->GetPosition.x;
				v2Point.y += Entities[i]->GetPosition().y - pEntity->GetPosition.y;
				nNeighborCount++;
			}
		}
	}

	if (nNeighborCount == 0)
		return v2Point;

	v2Point.x /= nNeighborCount;
	v2Point.y /= nNeighborCount;
	
	v2Point.x *= -1;
	v2Point.y *= -1;
	v2Point.normalise();

	return v2Point;
}

Vector2 Flocking::Update(Entity* pEntity, float deltaTime)
{
	DynamicArray<Entity*> Entities; // temp // Singlton?

	Vector2 v2Alignment = ComputeAlignment(pEntity, Entities); // Maybe add wight to each to further improve.
	Vector2 v2Cohesion = ComputeCohesion(pEntity, Entities); // Maybe add wight to each to further improve.
	Vector2 v2Separation = ComputeSeparation(pEntity, Entities); // Maybe add wight to each to further improve.

	Vector2 vel = pEntity->GetVelocity();
	vel.x += (v2Alignment.x + v2Cohesion.x + v2Separation.x);
	vel.y += (v2Alignment.y + v2Cohesion.y + v2Separation.y);
	vel.normalise();
	vel *= 80;
}