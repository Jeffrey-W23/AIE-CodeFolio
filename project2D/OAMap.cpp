// #include, using, etc
#include "OAMap.h"
#include "Circle.h"
#include "Sqr.h"

//--------------------------------------------------------------------------------------
// The one and only instance of this class
//--------------------------------------------------------------------------------------
OAMap* OAMap::m_instance = nullptr;

//--------------------------------------------------------------------------------------
// Default Constructor.
//--------------------------------------------------------------------------------------
OAMap::OAMap()
{
	// Push each of the shapes I want on the map to the array.
	m_aObstacle.PushBack(new Circle(Vector2(250, 365), 50));
	m_aObstacle.PushBack(new Sqr(Vector2(350, 515), 50));
	m_aObstacle.PushBack(new Circle(Vector2(150, 415), 50));
	m_aObstacle.PushBack(new Sqr(Vector2(600, 545), 50));
	m_aObstacle.PushBack(new Circle(Vector2(700, 365), 50));
	m_aObstacle.PushBack(new Sqr(Vector2(550, 215), 50));
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
OAMap::~OAMap()
{
	for (int i = 0; i < m_aObstacle.Size(); ++i)
	{
		delete m_aObstacle[i];
	}
}

//--------------------------------------------------------------------------------------
// Instance: The function for providing access.
//--------------------------------------------------------------------------------------
OAMap* OAMap::Instance()
{
	return m_instance;
}

//--------------------------------------------------------------------------------------
// Draw: A virtual function to render (or "draw") objects to the screen.
//
// Param:
//		renderer2D: a pointer to Renderer2D for rendering objects to screen.
//--------------------------------------------------------------------------------------
void OAMap::Draw(Renderer2D* m_2dRenderer)
{
	// Draw each of the Obstacles.
	for (int i = 0; i < m_aObstacle.Size(); ++i)
	{
		m_aObstacle[i]->Draw(m_2dRenderer);
	}
}

//--------------------------------------------------------------------------------------
// Update: A virtual function to update objects.
//
// Param:
//		deltaTime: Pass in deltaTime. A number that updates per second.
//--------------------------------------------------------------------------------------
void OAMap::Update(float deltaTime)
{
	// Update each of the Obstacles.
	for (int i = 0; i < m_aObstacle.Size(); ++i)
	{
		m_aObstacle[i]->Update(deltaTime);
	}
}

//--------------------------------------------------------------------------------------
// GetArray: Get the Map array.
//
// Returns:
//		DynamicArray: Returns a Dynamic Array of Base Obstacle pointers.
//--------------------------------------------------------------------------------------
DynamicArray<BaseObstacle*>& OAMap::GetArray()
{
	return m_aObstacle;
}