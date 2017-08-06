// #include, using, etc
#pragma once
#include "IBehaviour.h"
#include "Vector2.h"

//--------------------------------------------------------------------------------------
// KeyboardController object. Inheritance from IBehaviour.
//--------------------------------------------------------------------------------------
class KeyboardController : public IBehaviour
{
public:
	
	//--------------------------------------------------------------------------------------
	// Default Constructor. Taking in a float fWeighting.
	//--------------------------------------------------------------------------------------
	KeyboardController(float fWeighting);
	
	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	~KeyboardController();

	//--------------------------------------------------------------------------------------
	// Update: A virtual function from IBehaviour to update objects over time.
	//
	// Param:
	//		deltaTime: Pass in deltaTime. A number that updates per second.
	//		pEntity: a pointer to an entity.
	//--------------------------------------------------------------------------------------
	Vector2 Update(Entity* pEntity, float deltaTime);

protected:

	//--------------------------------------------------------------------------------------
	// a float for the behaviour speed.
	//--------------------------------------------------------------------------------------
	float speed;
	
	//--------------------------------------------------------------------------------------
	// A float for the behaviour mass.
	//--------------------------------------------------------------------------------------
	float mass;
	
	//--------------------------------------------------------------------------------------
	// A Vector2 for the behaviour direction.
	//--------------------------------------------------------------------------------------
	Vector2 direction;
};