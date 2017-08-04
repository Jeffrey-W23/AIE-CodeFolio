#pragma once
#include "State.h"
#include "Renderer2D.h"
#include "DynamicArray.h"
using namespace aie;

class Boid;

class FlockingState : public State
{
public:
	FlockingState();
	~FlockingState();

	void onEnter(StateMachine* pMachine);
	void onExit(StateMachine* pMachine);
	void onUpdate(float deltaTime, StateMachine* pMachine);
	void onDraw(Renderer2D* m_2dRenderer);

private:
	DynamicArray<Boid*>* m_Boids;
	Font* m_Font;
	Font* m_Font2;
};

