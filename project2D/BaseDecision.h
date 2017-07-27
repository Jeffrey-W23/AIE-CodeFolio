#pragma once

class Entity;

class BaseDecision 
{
public:
	BaseDecision() {};
	virtual ~BaseDecision() {};
	virtual void MakeDecision(Entity* pEntity, float deltaTime) = 0;
};