#pragma once
#include "State.h"
#include "Renderer2D.h"
using namespace aie;

class Enemy;
class Enemy4;

class PathState : public State
{
public:
	PathState();
	~PathState();

	void onEnter(StateMachine* pMachine);
	void onExit(StateMachine* pMachine);
	void onUpdate(float deltaTime, StateMachine* pMachine);
	void onDraw(Renderer2D* m_2dRenderer);

private:
	Enemy* m_Enemy;
	Enemy4* m_Enemy4;
	Font* m_Font;
	Font* m_Font2;
};

