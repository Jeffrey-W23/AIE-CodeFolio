#pragma once
#include "Entity.h"

class BTBaseNode;

enum EBehaviourType
{
	EBEHAVIOURTYPE_STOP,
	EBEHAVIOURTYPE_SEEK,
	EBEHAVIOURTYPE_FLEE
};

class Enemy3 : public Entity
{
public:
	Enemy3();
	~Enemy3();

	void Update(float deltaTime);
	void Draw(Renderer2D* m_2dRenderer);

	EBehaviourType m_eBehType;

private:
	BTBaseNode* m_pRoot;
};