#pragma once

class Entity;

class IBehaviour {
	
public:

	IBehaviour();
	~IBehaviour();

	virtual void Update(Entity* pEntity, float deltaTime) = 0;
};

