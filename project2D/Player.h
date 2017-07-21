#pragma once
#include "BaseAgent.h"

class Player : public BaseAgent
{
public:
	Player();
	~Player();

	void Update(float deltaTime);
	void Draw(Renderer2D* m_2dRenderer);

private:
	AIStateMachine* m_AIStateMachine;
};