// #include, using, etc
#pragma once
#include "IBehaviour.h"
#include "DynamicArray.h"

// forward declarations
class Boid;

//--------------------------------------------------------------------------------------
// Flocking object. Inheritance from IBehaviour.
//--------------------------------------------------------------------------------------
class Flocking : public IBehaviour
{
public:
	
	//--------------------------------------------------------------------------------------
	// Default Constructor. Taking in a float fWeighting and A DynamicArray of boid pointers
	//--------------------------------------------------------------------------------------
	Flocking(float fWeighting, DynamicArray<Boid*>* aEntityList);
	
	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	~Flocking();

	//--------------------------------------------------------------------------------------
	// ComputeAlignment: Compute the alignment behaviour.
	//
	// Returns:
	//		Vector2: returns the computed alignment.
	// Param:
	//		pEntity: a pointer to an entity.
	//--------------------------------------------------------------------------------------
	Vector2 ComputeAlignment(Entity* pEntity);
	
	//--------------------------------------------------------------------------------------
	// ComputeCohesion: Compute the cohesion behaviour.
	//
	// Returns:
	//		Vector2: returns the computed cohesion.
	// Param:
	//		pEntity: a pointer to an entity.
	//--------------------------------------------------------------------------------------
	Vector2 ComputeCohesion(Entity* pEntity);
	
	//--------------------------------------------------------------------------------------
	// ComputeSeparation: Compute the separation behaviour.
	//
	// Returns:
	//		Vector2: returns the computed separation.
	// Param:
	//		pEntity: a pointer to an entity.
	//--------------------------------------------------------------------------------------
	Vector2 ComputeSeparation(Entity* pEntity);
	
	//--------------------------------------------------------------------------------------
	// Update: A virtual function from IBehaviour to update objects over time.
	//
	// Param:
	//		deltaTime: Pass in deltaTime. A number that updates per second.
	//		pEntity: a pointer to an entity.
	//--------------------------------------------------------------------------------------
	Vector2 Update(Entity* pEntity, float deltaTime);

private:
	
	//--------------------------------------------------------------------------------------
	// A DynamicArray of Boid pointers.
	//--------------------------------------------------------------------------------------
	DynamicArray<Boid*>* m_aEntities;
};