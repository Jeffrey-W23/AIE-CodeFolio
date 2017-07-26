#pragma once
#include "AIState.h"
#include "Renderer2D.h"
#include "Follow.h"
using namespace aie;

class FollowState : public AIState
{
public:
	FollowState();
	~FollowState();

	void onEnter(AIStateMachine* pMachine);
	void onExit(AIStateMachine* pMachine);
	void onUpdate(float deltaTime, Entity* pEntity, AIStateMachine* pMachine);
	void onDraw(Renderer2D* m_2dRenderer);
};