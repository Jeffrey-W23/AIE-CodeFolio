#pragma once
#include "Vector2.h"
#include "Renderer2D.h"
#include "AIStateMachine.h"
#include "DynamicArray.h"
#include "IBehaviour.h"

using namespace aie;

class BaseAgent {
public:

	BaseAgent();
	~BaseAgent();

	virtual void Update(float deltaTime);
	virtual void Draw(Renderer2D* m_2dRenderer);

//protected: //ask richard
	Vector2 m_force;
	Vector2 m_acceleration;
	Vector2 m_velocity;
	Vector2 m_position;
};