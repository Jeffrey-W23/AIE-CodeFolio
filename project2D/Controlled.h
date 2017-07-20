#pragma once
#include "State.h"
#include "StateMachine.h"
#include "Renderer2D.h"
#include "KeyboardController.h"
using namespace aie;

class Controlled : public State
{
public:
	Controlled();
	~Controlled();

	void onEnter(StateMachine* pMachine);
	void onExit(StateMachine* pMachine);
	void onUpdate(float deltaTime, StateMachine* pMachine);
	void onDraw(Renderer2D* m_2dRenderer);

private:
	DynamicArray<IBehaviour*> m_behaviours;
	KeyboardController* m_controller;
};
