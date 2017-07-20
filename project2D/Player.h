#pragma once
#include "BaseAgent.h"
#include "KeyboardController.h"

class Player : public BaseAgent
{
public:
	Player();
	~Player();

	void Update(float deltaTime);
	void Draw(Renderer2D* m_2dRenderer);

private:
	StateMachine* m_StateMachine;
	//KeyboardController* m_controller;
};