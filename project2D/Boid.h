// #include, using, etc
#pragma once
#include "Entity.h"

//--------------------------------------------------------------------------------------
// Boid object. Inheritance from Entity.
//--------------------------------------------------------------------------------------
class Boid : public Entity
{
public:

	//--------------------------------------------------------------------------------------
	// Default Constructor. Taking in a DynamicArray pointer of Boid pointers.
	//--------------------------------------------------------------------------------------
	Boid(DynamicArray<Boid*>* aEntityList);

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	~Boid();

	//--------------------------------------------------------------------------------------
	// Update: A function to update objects.
	//
	// Param:
	//		deltaTime: Pass in deltaTime. A number that updates per second.
	//--------------------------------------------------------------------------------------
	void Update(float deltaTime);

	//--------------------------------------------------------------------------------------
	// Draw: A function to render (or "draw") objects to the screen.
	//
	// Param:
	//		renderer2D: a pointer to Renderer2D for rendering objects to screen.
	//--------------------------------------------------------------------------------------
	void Draw(Renderer2D* m_2dRenderer);
};