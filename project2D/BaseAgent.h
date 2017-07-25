#pragma once
#include "Vector2.h"
#include "Renderer2D.h"
#include "AIStateMachine.h"

using namespace aie;

class BaseAgent {
public:

	BaseAgent();
	virtual ~BaseAgent();

//	virtual void Update(float deltaTime);
//	virtual void Draw(Renderer2D* m_2dRenderer);
//
//	// Getters
//	Vector2 GetPosition();
//	Vector2 GetForce();
//	Vector2 GetVelocity();
//	Vector2 GetAcceleration();
//
//	// Setters
//	void SetPosition(Vector2 nPos);
//	void SetForce(Vector2 nForce);
//	void SetVelocity(Vector2 nVel);
//	void SetAcceleration(Vector2 nAccel);
//
//protected:
//	Vector2 m_force;
//	Vector2 m_acceleration;
//	Vector2 m_velocity;
//	Vector2 m_position;
//	AIStateMachine* m_AIStateMachine;
};