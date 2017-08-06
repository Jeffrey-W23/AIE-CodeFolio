// #include, using, etc
#include "Seek.h"
#include "Input.h"
#include "Entity.h"
using namespace aie;

//--------------------------------------------------------------------------------------
// Default Constructor. Taking in a float fWeighting.
//--------------------------------------------------------------------------------------
Seek::Seek(float fWeighting) : IBehaviour(fWeighting)
{
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
Seek::~Seek()
{
}

//--------------------------------------------------------------------------------------
// Update: A virtual function from IBehaviour to update objects over time.
//
// Param:
//		deltaTime: Pass in deltaTime. A number that updates per second.
//		pEntity: a pointer to an entity.
//--------------------------------------------------------------------------------------
Vector2 Seek::Update(Entity* pEntity, float deltaTime)
{
	// Seek towards the mouse
	int nMouseX;
	int nMouseY;

	Input::getInstance()->getMouseXY(&nMouseX, &nMouseY);
	Vector2 v2MousePos(nMouseX, nMouseY);

	Vector2 v2Dir = v2MousePos - pEntity->GetPosition();
	v2Dir.normalise();

	return v2Dir * 100.0f * deltaTime;
}