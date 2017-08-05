#pragma once
#include "Entity.h"

class SeekFleeEntity : public Entity
{
public:
	SeekFleeEntity();
	~SeekFleeEntity();

	void Update(float deltaTime);
	void Draw(Renderer2D* m_2dRenderer);
};