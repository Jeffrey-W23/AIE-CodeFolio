#pragma once

class Entity;

class BaseDecision 
{
public:
	virtual void MakeDecision(Entity* pEntity, float deltaTime) = 0;
};