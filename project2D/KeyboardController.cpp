#include "KeyboardController.h"
#include "Entity.h"
#include "Input.h"

KeyboardController::KeyboardController(float fWeighting) : IBehaviour(fWeighting)
{
	speed = 20.0f;
	mass = 5.0f;
}

KeyboardController::~KeyboardController()
{
}

Vector2 KeyboardController::Update(Entity* pEntity, float deltaTime)
{
	//Play around with
	Vector2 pos = pEntity->GetPosition();

	aie::Input* input = aie::Input::getInstance();

	if (input->isKeyDown(aie::INPUT_KEY_W))
		pos.y += 100 * deltaTime;
		//direction.y += 10;

	if (input->isKeyDown(aie::INPUT_KEY_S))
		pos.y -= 100 * deltaTime;
			//direction.y -= 10;

	if (input->isKeyDown(aie::INPUT_KEY_D))
		pos.x += 100 * deltaTime;
		//direction.x += 10;

	if (input->isKeyDown(aie::INPUT_KEY_A))
		pos.x -= 100 * deltaTime;
		//direction.x -= 10;

	pEntity->SetPosition(pos);

	/*agent->m_force = direction * speed;
	agent->m_acceleration = agent->m_force / mass;
	agent->m_velocity += agent->m_acceleration * deltaTime;
	agent->m_position += agent->m_velocity * deltaTime;*/
	return Vector2(0, 0);
}
