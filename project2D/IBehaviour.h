#pragma once

class BaseAgent;

class IBehaviour {
	
public:

	IBehaviour();
	~IBehaviour();

	virtual void Update(BaseAgent* agent, float deltaTime) = 0;
};

