#pragma once
#include "Entity.h"

class BaseQuestion;

class DecisionEntity : public Entity
{
public:
	DecisionEntity();
	~DecisionEntity();

	void Update(float deltaTime);
	void Draw(Renderer2D* m_2dRenderer);

private:
	BaseQuestion* m_pRoot;
};