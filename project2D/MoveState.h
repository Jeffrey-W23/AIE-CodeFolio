#pragma once
#include "AIState.h"
#include "Renderer2D.h"
#include "Follow.h"
using namespace aie;

class MoveState : public AIState
{
public:
	MoveState();
	~MoveState();

	void onEnter(AIStateMachine* pMachine);
	void onExit(AIStateMachine* pMachine);
	void onUpdate(float deltaTime, Entity* pEntity, AIStateMachine* pMachine);
	void onDraw(Renderer2D* m_2dRenderer);
};