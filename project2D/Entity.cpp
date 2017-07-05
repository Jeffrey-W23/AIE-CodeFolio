// #include, using, etc
#include "Entity.h"
#include <crtdbg.h>

//--------------------------------------------------------------------------------------
// Default Constructor.
//--------------------------------------------------------------------------------------
Entity::Entity()
{
	// start the active status as false 
	m_bActive = false;
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
Entity::~Entity()
{
}

//--------------------------------------------------------------------------------------
// SetActive: A function to set the object to active for the object pool
//
// Param:
//		m_bActive: a bool for if you want the object to be active or not.
//--------------------------------------------------------------------------------------
void Entity::SetActive(bool bActive)
{
	m_bActive = bActive;
}

//--------------------------------------------------------------------------------------
// GetActive: A function to check if an object is active or not for the object pool.
//--------------------------------------------------------------------------------------
bool Entity::GetActive()
{
	return m_bActive;
}

//--------------------------------------------------------------------------------------
// Update: A function to update objects.
//
// Param:
//		deltaTime: Pass in deltaTime. A number that updates per second.
//--------------------------------------------------------------------------------------
void Entity::Update()
{
}

//--------------------------------------------------------------------------------------
// Draw: A function to render (or "draw") objects to the screen.
//
// Param:
//		renderer2D: a pointer to Renderer2D for rendering objects to screen.
//--------------------------------------------------------------------------------------
void Entity::Draw()
{
}