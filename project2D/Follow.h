#pragma once
#include "IBehaviour.h"
#include "AStarNode.h"
#include "Grid.h"

class Follow : public IBehaviour
{
public:
	Follow();
	~Follow();

	void Update(Entity* pEntity, float deltaTime);

protected:
	Grid* m_pGrid;
	AStar* m_pAStar;
	DynamicArray<AStarNode*> m_path;
	int m_NextNode;
};