#pragma once
#include "State.h"
#include "Renderer2D.h"
using namespace aie;

class Player;

class PlayerState : public State
{
public:
	PlayerState();
	~PlayerState();

	void onEnter(StateMachine* pMachine);
	void onExit(StateMachine* pMachine);
	void onUpdate(float deltaTime, StateMachine* pMachine);
	void onDraw(Renderer2D* m_2dRenderer);

private:
	Player* m_Player;
	Font* m_Font;
	Font* m_Font2;
};

