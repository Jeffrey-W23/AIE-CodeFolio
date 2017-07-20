#pragma once
#include "State.h"
#include "StateMachine.h"
#include "Renderer2D.h"
using namespace aie;

class Patrol : public State
{
public:
	Patrol();
	~Patrol();

	void onEnter(StateMachine* pMachine);
	void onExit(StateMachine* pMachine);
	void onUpdate(float deltaTime, StateMachine* pMachine);
	void onDraw(Renderer2D* m_2dRenderer);
};