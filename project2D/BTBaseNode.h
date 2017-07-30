#pragma once

class Entity;

enum EBehaviourResult
{
	EBHAVIOUR_FAILURE,
	EBHAVIOUR_SUCCESS,
	EBHAVIOUR_PENDING
};

class BTBaseNode
{
public:
	BTBaseNode() {};
	virtual ~BTBaseNode() {};
	virtual EBehaviourResult Execute(Entity* pEntity, float deltaTime) = 0;
};