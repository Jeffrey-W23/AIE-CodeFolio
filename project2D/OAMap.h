// #include, using, etc
#pragma once
#include "DynamicArray.h"
#include "Renderer2D.h"
using namespace aie;

// forward declarations
class BaseObstacle;
class Circle;
class Sqr;

//--------------------------------------------------------------------------------------
// OAMap object.
//--------------------------------------------------------------------------------------
class OAMap
{
private:

	//--------------------------------------------------------------------------------------
	// Default Constructor.
	//--------------------------------------------------------------------------------------
	OAMap();

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	~OAMap();

	//--------------------------------------------------------------------------------------
	// The one and only instance of this class
	//--------------------------------------------------------------------------------------
	static OAMap* m_instance;

public:

	//--------------------------------------------------------------------------------------
	// Draw: A function to render (or "draw") objects to the screen.
	//
	// Param:
	//		renderer2D: a pointer to Renderer2D for rendering objects to screen.
	//--------------------------------------------------------------------------------------
	void Draw(Renderer2D* m_2dRenderer);

	//--------------------------------------------------------------------------------------
	// Update: A function to update objects.
	//
	// Param:
	//		deltaTime: Pass in deltaTime. A number that updates per second.
	//--------------------------------------------------------------------------------------
	void Update(float deltaTime);

	//--------------------------------------------------------------------------------------
	// GetArray: Get the Map array.
	//
	// Returns:
	//		DynamicArray: Returns a Dynamic Array of Base Obstacle pointers.
	//--------------------------------------------------------------------------------------
	DynamicArray<BaseObstacle*>& GetArray();

	//--------------------------------------------------------------------------------------
	// create: A function for creating an instance of the Map.
	//--------------------------------------------------------------------------------------
	static void create() { m_instance = new OAMap(); }

	//--------------------------------------------------------------------------------------
	// destroy: A function for deleting the Map instance.
	//--------------------------------------------------------------------------------------
	static void destroy() { delete m_instance; }

	//--------------------------------------------------------------------------------------
	// Instance: The function for providing access.
	//--------------------------------------------------------------------------------------
	static OAMap* Instance();

private:

	//--------------------------------------------------------------------------------------
	// A DynamicArray of BaseObstacle pointers.
	//--------------------------------------------------------------------------------------
	DynamicArray<BaseObstacle*> m_aObstacle;
};