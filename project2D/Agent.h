#pragma once
#include "Vector2.h"
#include "DynamicArray.h"
#include "IBehaviour.h"
#include "Renderer2D.h"
using namespace aie;

class Agent {
public:

	Agent();
	~Agent();

	virtual void update(float deltaTime) 
	{
		for (int i = 0; i < m_behaviours.Size(); ++i)
			m_behaviours[i]->update(this, deltaTime);
	}

	virtual void draw(Renderer2D m_2dRenderer){}

protected:

	DynamicArray<IBehaviour*> m_behaviours;
	Vector2 m_force;
	Vector2 m_acceleration;
	Vector2 m_velocity;
	Vector2 m_position;
};