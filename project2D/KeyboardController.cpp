// #include, using, etc
#include "KeyboardController.h"
#include "Entity.h"
#include "Input.h"

//--------------------------------------------------------------------------------------
// Default Constructor. Taking in a float fWeighting.
//--------------------------------------------------------------------------------------
KeyboardController::KeyboardController(float fWeighting) : IBehaviour(fWeighting)
{
	// Set vars
	speed = 20.0f;
	mass = 5.0f;
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
KeyboardController::~KeyboardController()
{
}

//--------------------------------------------------------------------------------------
// Update: A virtual function from IBehaviour to update objects over time.
//
// Param:
//		deltaTime: Pass in deltaTime. A number that updates per second.
//		pEntity: a pointer to an entity.
//--------------------------------------------------------------------------------------
Vector2 KeyboardController::Update(Entity* pEntity, float deltaTime)
{
	// Move the entity by keyboard presses.
	Vector2 pos = pEntity->GetPosition();

	aie::Input* input = aie::Input::getInstance();

	if (input->isKeyDown(aie::INPUT_KEY_W))
		pos.y += 100 * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_S))
		pos.y -= 100 * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_D))
		pos.x += 100 * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_A))
		pos.x -= 100 * deltaTime;

	// Set the position.
	pEntity->SetPosition(pos);
	return Vector2(0, 0);
}
