#pragma once
#include "AIState.h"
#include "Renderer2D.h"
#include "Flocking.h"
using namespace aie;

class Boid;

class FlockState : public AIState
{
public:
	FlockState(DynamicArray<Boid*>* aEntityList);
	~FlockState();

	void onEnter(AIStateMachine* pMachine);
	void onExit(AIStateMachine* pMachine);
	void onUpdate(float deltaTime, Entity* pEntity, AIStateMachine* pMachine);
	void onDraw(Renderer2D* m_2dRenderer);

private:
	bool m_bStop;
};