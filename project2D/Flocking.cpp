#include "Flocking.h"
#include "Input.h"
#include "Entity.h"
#include "Boid.h"
#include "Vector2.h"
using namespace aie;

Flocking::Flocking(float fWeighting, DynamicArray<Boid*>* aEntityList) : IBehaviour(fWeighting)
{
	m_aEntities = aEntityList;
}

Flocking::~Flocking()
{
}

Vector2 Flocking::ComputeAlignment(Entity* pEntity)
{
	Vector2 v2Point;
	int nNeighborCount = 0;

	for (int i = 0; i < m_aEntities->Size(); ++i)
	{
		if ((*m_aEntities)[i] != pEntity)
		{
			if (Vector2::Distance((*m_aEntities)[i]->GetPosition(), pEntity->GetPosition()) < 300)
			{
				v2Point.x += (*m_aEntities)[i]->GetVelocity().x;
				v2Point.y += (*m_aEntities)[i]->GetVelocity().y;
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

Vector2 Flocking::ComputeCohesion(Entity* pEntity)
{
	Vector2 v2Point;
	int nNeighborCount = 0;

	for (int i = 0; i < m_aEntities->Size(); ++i)
	{
		if ((*m_aEntities)[i] != pEntity)
		{
			if (Vector2::Distance((*m_aEntities)[i]->GetPosition(), pEntity->GetPosition()) < 300)
			{
				v2Point.x += (*m_aEntities)[i]->GetPosition().x;
				v2Point.y += (*m_aEntities)[i]->GetPosition().y;
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

Vector2 Flocking::ComputeSeparation(Entity* pEntity)
{
	Vector2 v2Point;
	int nNeighborCount = 0;

	for (int i = 0; i < m_aEntities->Size(); ++i)
	{
		if ((*m_aEntities)[i] != pEntity)
		{
			if (Vector2::Distance((*m_aEntities)[i]->GetPosition(), pEntity->GetPosition()) < 150)
			{
				v2Point.x += (*m_aEntities)[i]->GetPosition().x - pEntity->GetPosition().x;
				v2Point.y += (*m_aEntities)[i]->GetPosition().y - pEntity->GetPosition().y;
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
	Vector2 v2Alignment = ComputeAlignment(pEntity); // Maybe add wight to each to further improve.
	Vector2 v2Cohesion = ComputeCohesion(pEntity); // Maybe add wight to each to further improve.
	Vector2 v2Separation = ComputeSeparation(pEntity); // Maybe add wight to each to further improve.

	Vector2 vel = pEntity->GetVelocity();
	vel.x += (v2Alignment.x * 8.0f + v2Cohesion.x * 12.0f + v2Separation.x * 12.0f);
	vel.y += (v2Alignment.y * 8.0f + v2Cohesion.y * 12.0f + v2Separation.y * 12.0f);
	vel.normalise();
	vel *= 80;

	return vel;
}