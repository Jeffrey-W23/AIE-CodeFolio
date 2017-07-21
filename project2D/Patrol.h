#pragma once
#include "AIState.h"
#include "Renderer2D.h"
#include "DynamicArray.h"
#include "IBehaviour.h"
#include "AIStateMachine.h"
using namespace aie;

class Patrol : public AIState
{
public:
	Patrol();
	~Patrol();

	void onEnter(AIStateMachine* pMachine);
	void onExit(AIStateMachine* pMachine);
	void onUpdate(float deltaTime, BaseAgent* agent, AIStateMachine* pMachine);
	void onDraw(Renderer2D* m_2dRenderer);

private:
	DynamicArray<IBehaviour*> m_behaviours;
};