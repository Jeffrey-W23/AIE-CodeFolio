#pragma once
#include "State.h"
#include "Renderer2D.h"
using namespace aie;

class Enemy2;

class DecisionState : public State
{
public:
	DecisionState();
	~DecisionState();

	void onEnter(StateMachine* pMachine);
	void onExit(StateMachine* pMachine);
	void onUpdate(float deltaTime, StateMachine* pMachine);
	void onDraw(Renderer2D* m_2dRenderer);

private:
	Enemy2* m_Enemy2;
	Font* m_Font;
	Font* m_Font2;
};

