// #include, using, etc
#include "Sqr.h"

//--------------------------------------------------------------------------------------
// Default Constructor.
//--------------------------------------------------------------------------------------
Sqr::Sqr(Vector2 v2Pos, float fSize)
{
	// Set the shape type.
	m_eType = ETYPE_SQR;

	// Set the pos and size of the shape.
	m_v2Pos = v2Pos;
	m_fSize = fSize;
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
Sqr::~Sqr()
{
}

//--------------------------------------------------------------------------------------
// Draw: A virtual function to render (or "draw") objects to the screen.
//
// Param:
//		renderer2D: a pointer to Renderer2D for rendering objects to screen.
//--------------------------------------------------------------------------------------
void Sqr::Draw(Renderer2D* m_2dRenderer)
{
	m_2dRenderer->setRenderColour(1, 0, 1, 1);
	m_2dRenderer->drawBox(m_v2Pos.x, m_v2Pos.y, m_fSize, m_fSize);
	m_2dRenderer->setRenderColour(0xFFFFFFFF);
}

//--------------------------------------------------------------------------------------
// Update: A virtual function to update objects.
//
// Param:
//		deltaTime: Pass in deltaTime. A number that updates per second.
//--------------------------------------------------------------------------------------
void Sqr::Update(float deltaTime)
{

}