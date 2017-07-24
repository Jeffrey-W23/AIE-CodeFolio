#include "KeyboardController.h"
#include "BaseAgent.h"
#include "Input.h"

KeyboardController::KeyboardController()
{
	speed = 20.0f;
	mass = 5.0f;
}

KeyboardController::~KeyboardController()
{
}

void KeyboardController::Update(BaseAgent* agent, float deltaTime)
{
	//Play around with
	Vector2 pos = agent->GetPosition();

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

	agent->SetPosition(pos);

	/*agent->m_force = direction * speed;
	agent->m_acceleration = agent->m_force / mass;
	agent->m_velocity += agent->m_acceleration * deltaTime;
	agent->m_position += agent->m_velocity * deltaTime;*/
}
