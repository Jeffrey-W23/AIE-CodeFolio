#pragma once
#include "AIState.h"
#include "Renderer2D.h"
#include "KeyboardController.h"
using namespace aie;

class Controlled : public AIState
{
public:
	Controlled();
	~Controlled();

	void onEnter(AIStateMachine* pMachine);
	void onExit(AIStateMachine* pMachine);
	void onUpdate(float deltaTime, Entity* pEntity, AIStateMachine* pMachine);
	void onDraw(Renderer2D* m_2dRenderer);

private:
	KeyboardController* m_controller;
};
