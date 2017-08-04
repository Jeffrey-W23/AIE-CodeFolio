#pragma once
#include "State.h"
#include "Renderer2D.h"
using namespace aie;

class Enemy3;

class BehaviourState : public State
{
public:
	BehaviourState();
	~BehaviourState();

	void onEnter(StateMachine* pMachine);
	void onExit(StateMachine* pMachine);
	void onUpdate(float deltaTime, StateMachine* pMachine);
	void onDraw(Renderer2D* m_2dRenderer);

private:
	Enemy3* m_Enemy3;
	Font* m_Font;
	Font* m_Font2;
};

