// #include, using, etc
#pragma once
#include "Entity.h"

// forward declarations
class BaseQuestion;

//--------------------------------------------------------------------------------------
// DecisionEntity object. Inheritance from Entity.
//--------------------------------------------------------------------------------------
class DecisionEntity : public Entity
{
public:

	//--------------------------------------------------------------------------------------
	// Default Constructor.
	//--------------------------------------------------------------------------------------
	DecisionEntity();

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	~DecisionEntity();

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

private:

	//--------------------------------------------------------------------------------------
	// A BaseQuestion pointer.
	//--------------------------------------------------------------------------------------
	BaseQuestion* m_pRoot;
};