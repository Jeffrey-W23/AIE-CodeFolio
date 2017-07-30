#pragma once
#include "AIState.h"
#include "Renderer2D.h"
using namespace aie;

class ControllerState : public AIState
{
public:
	ControllerState();
	~ControllerState();

	void onEnter(AIStateMachine* pMachine);
	void onExit(AIStateMachine* pMachine);
	void onUpdate(float deltaTime, Entity* pEntity, AIStateMachine* pMachine);
	void onDraw(Renderer2D* m_2dRenderer);

private:
	bool m_bStop;
};
