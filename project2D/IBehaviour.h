#pragma once
 
class Agent;

class IBehaviour {
	
public:

	IBehaviour();
	~IBehaviour();

	virtual bool update(Agent* agent, float deltaTime) = 0;
};

