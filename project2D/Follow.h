#pragma once
#include "IBehaviour.h"
#include "AStarNode.h"

struct GridNode;
class AStar;

class Follow : public IBehaviour
{
public:
	Follow();
	~Follow();

	void Update(BaseAgent* agent, float deltaTime);

protected:
	GridNode** m_ppGrid;
	AStar* m_pAStar;
};

