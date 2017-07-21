#pragma once
#include "AIState.h"
#include "Renderer2D.h"
#include "KeyboardController.h"
#include "DynamicArray.h"
using namespace aie;

class Controlled : public AIState
{
public:
	Controlled();
	~Controlled();

	void onEnter(AIStateMachine* pMachine);
	void onExit(AIStateMachine* pMachine);
	void onUpdate(float deltaTime, BaseAgent* agent, AIStateMachine* pMachine);
	void onDraw(Renderer2D* m_2dRenderer);

private:
	DynamicArray<IBehaviour*> m_behaviours;
	KeyboardController* m_controller;
};
