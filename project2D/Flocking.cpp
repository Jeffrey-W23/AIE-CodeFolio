// #include, using, etc
#include "Flocking.h"
#include "Input.h"
#include "Entity.h"
#include "Boid.h"
#include "Vector2.h"
using namespace aie;

//--------------------------------------------------------------------------------------
// Default Constructor. Taking in a float fWeighting and A DynamicArray of boid pointers
//--------------------------------------------------------------------------------------
Flocking::Flocking(float fWeighting, DynamicArray<Boid*>* aEntityList) : IBehaviour(fWeighting)
{
	// set vars
	m_aEntities = aEntityList;
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
Flocking::~Flocking()
{
}

//--------------------------------------------------------------------------------------
// ComputeAlignment: Compute the alignment behaviour.
//
// Returns:
//		Vector2: returns the computed alignment.
// Param:
//		pEntity: a pointer to an entity.
//--------------------------------------------------------------------------------------
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

//--------------------------------------------------------------------------------------
// ComputeCohesion: Compute the cohesion behaviour.
//
// Returns:
//		Vector2: returns the computed cohesion.
// Param:
//		pEntity: a pointer to an entity.
//--------------------------------------------------------------------------------------
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

//--------------------------------------------------------------------------------------
// ComputeSeparation: Compute the separation behaviour.
//
// Returns:
//		Vector2: returns the computed separation.
// Param:
//		pEntity: a pointer to an entity.
//--------------------------------------------------------------------------------------
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

//--------------------------------------------------------------------------------------
// Update: A virtual function from IBehaviour to update objects over time.
//
// Param:
//		deltaTime: Pass in deltaTime. A number that updates per second.
//		pEntity: a pointer to an entity.
//--------------------------------------------------------------------------------------
Vector2 Flocking::Update(Entity* pEntity, float deltaTime)
{
	// Get each of the behaviours
	Vector2 v2Alignment = ComputeAlignment(pEntity);
	Vector2 v2Cohesion = ComputeCohesion(pEntity);
	Vector2 v2Separation = ComputeSeparation(pEntity);

	// Weight against each other
	Vector2 vel = pEntity->GetVelocity();
	vel.x += (v2Alignment.x * 8.0f + v2Cohesion.x * 12.0f + v2Separation.x * 12.0f);
	vel.y += (v2Alignment.y * 8.0f + v2Cohesion.y * 12.0f + v2Separation.y * 12.0f);
	vel.normalise();
	vel *= 80;

	// Return the weight
	return vel;
}