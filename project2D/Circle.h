// #include, using, etc
#pragma once
#include "BaseObstacle.h"

//--------------------------------------------------------------------------------------
// Circle object. Inheritance from BaseObstacle.
//--------------------------------------------------------------------------------------
class Circle : public BaseObstacle
{
public:

	//--------------------------------------------------------------------------------------
	// Default Constructor.
	//--------------------------------------------------------------------------------------
	Circle(Vector2 v2Pos, float fSize);

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	~Circle();

	//--------------------------------------------------------------------------------------
	// Draw: A virtual function to render (or "draw") objects to the screen.
	//
	// Param:
	//		renderer2D: a pointer to Renderer2D for rendering objects to screen.
	//--------------------------------------------------------------------------------------
	void Draw(Renderer2D* m_2dRenderer);

	//--------------------------------------------------------------------------------------
	// Update: A virtual function to update objects.
	//
	// Param:
	//		deltaTime: Pass in deltaTime. A number that updates per second.
	//--------------------------------------------------------------------------------------
	void Update(float deltaTime);

private:
};

