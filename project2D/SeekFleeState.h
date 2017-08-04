#pragma once
#include "State.h"
#include "Renderer2D.h"
using namespace aie;

class Enemy1;

class SeekFleeState : public State
{
public:
	SeekFleeState();
	~SeekFleeState();

	void onEnter(StateMachine* pMachine);
	void onExit(StateMachine* pMachine);
	void onUpdate(float deltaTime, StateMachine* pMachine);
	void onDraw(Renderer2D* m_2dRenderer);

private:
	Enemy1* m_Enemy1;
	Font* m_Font;
	Font* m_Font2;
};

