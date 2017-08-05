#pragma once
#include "Entity.h"

class BTBaseNode;

enum EBehaviourType
{
	EBEHAVIOURTYPE_STOP,
	EBEHAVIOURTYPE_OA,
};

class BehaviourEntity : public Entity
{
public:
	BehaviourEntity();
	~BehaviourEntity();

	void Update(float deltaTime);
	void Draw(Renderer2D* m_2dRenderer);

	EBehaviourType m_eBehType;

private:
	BTBaseNode* m_pRoot;
	bool m_bStop;
};